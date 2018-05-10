#include"Headers_include.hpp"
#include"Constant_expressions.hpp"





Game::Game()
{

	

	for (int i = 0; i < 10; ++i)
	{
		stage.emplace_back();
		for (int j = 0; j < 10; ++j)
		{
			stage[i].emplace_back();
		}
	}


	for(auto &S: stage)
		for (auto &s : S)
		{
			s.set_state(NONE);
			s.set_score(1);
		}

	agent_Blue[0].set_color(BLUE);
	agent_Blue[0].set_point(0, 0);

	agent_Blue[1].set_color(BLUE);
	agent_Blue[1].set_point(5, 0);

	agent_Yellow[0].set_color(YELLOW);
	agent_Yellow[0].set_point(0, 5);

	agent_Yellow[1].set_color(YELLOW);
	agent_Yellow[1].set_point(5, 5);

	mode = INIT;

	inputting = 0;
}

void Game::make_stage()
{

	renderer.set_coodinate(stage[0].size(), stage.size());

	renderer.Draw_line();

	int i = 0, j = 0;
	for (const auto S : stage)
	{
		for (const auto s : S)
		{
	

			renderer.Draw_number(j, i, stage[i][j].get_score());

			
			++j;
		}
		
		++i;
		j = 0;
	}

	
	
}


int Game::score_calcurate(const int COLOR)//色を渡すとその色の点数を返す
{
	
	for (auto &S : stage)//checkstage作成
	{
		checkstage.emplace_back();

		for (auto &s : S)
		{

			if (s.get_state() != COLOR)
				checkstage.back().emplace_back(true);
			else
				checkstage.back().emplace_back(false);

		}
	}
			
	for (auto i = checkstage.begin(); i < checkstage.end(); ++i)//自身の色じゃない未探索マス探して探索開始
	{
		const int index_R = i - checkstage.begin();

		for (auto j = checkstage[index_R].begin(); j < checkstage[index_R].end(); ++j)
		{
			const int index_C = j - checkstage[index_R].begin();

			if (checkstage[index_R][index_C])
			{
				check_within(index_C, index_R, COLOR);

			}
		}
	}
		
	//ここからスコア計算

	int score = 0;

	for(const auto S : stage)
		for (const auto s : S)
		{
			score += s.get_score();
		}

	return score;

}







bool Game::check_within(const int X, const int Y, const int COLOR)
{
	const auto lmd_isRightPoint = [&](int _X, int _Y)->bool
	{
		if (_Y <= 0 || _Y >= stage.size() || _X <= 0 || _X >= stage[0].size())
			return false;
		else 
			return true;
	};


	if (lmd_isRightPoint(X, Y) && !checkstage[Y][X])//壁に接していて自色のマスじゃなかったら
		return false;

	checkstage[Y][X] = false;//すでに来た場所ということでチェック入れる

	if (checkstage[Y - 1][X] && lmd_isRightPoint(X, Y - 1))//上が自色のマスもしくはすでに来た場所じゃなかったら
	{
		if (!check_within(X, Y - 1, COLOR))//上について同じように調べる
	   		return false;
	}
	if (checkstage[Y + 1][X] && lmd_isRightPoint(X, Y + 1))//下が同上
	{
		if (!check_within(X, Y + 1, COLOR))//下について調べる
			return false;
	}
	if (checkstage[Y][X + 1] && lmd_isRightPoint(X + 1, Y))//右が同上
	{
		if (!check_within(X - 1, Y, COLOR))//右について調べる
			return false;
	}
	if (checkstage[Y][X - 1] && lmd_isRightPoint(X - 1, Y))//左が同上
	{
		if (!check_within(X + 1, Y, COLOR))//左について調べる
			return false;
	}

	//ここから下に来れるということは四隅が壁じゃないまま詰まったマス = 囲まれている

	if (COLOR == BLUE)
	{
		if(stage[Y][X].get_state() == INSIDE_Y)
			stage[Y][X].set_state(INSIDE_BOTH);
		else
			stage[Y][X].set_state(INSIDE_B);

	}
	else if (COLOR == YELLOW)
	{
		if (stage[Y][X].get_state() == INSIDE_B)
			stage[Y][X].set_state(INSIDE_BOTH);
		else
			stage[Y][X].set_state(INSIDE_Y);
	}


	return true;
	



}


void Game::Draw_update()
{
	renderer.Draw_line();//ステージの線描画

	int i = 0, j = 0;


	for (const auto S : stage)//ステージの色がある場所描画
	{
		
		for (const auto s : S)
		{
			renderer.Draw_color(j, i, s.get_state());

			++j;
		}
		++i;
		j = 0;
	}

	i = 0, j = 0;

	for (const auto S : stage)//スコア表示
	{
		for (const auto s : S)
		{


			renderer.Draw_number(j, i, stage[i][j].get_score());


			++j;
		}

		++i;
		j = 0;
	}




	for (int i = 0; i < 2; ++i)//エージェント描画
	{
		renderer.Draw_Agent(agent_Blue[i].get_xpoint(), agent_Blue[i].get_ypoint(), BLUE);

		renderer.Draw_Agent(agent_Yellow[i].get_xpoint(), agent_Yellow[i].get_ypoint(), YELLOW);
	}


	



	


	//スコア実装		



}

void Game::Turn(Agent* AGENT, const int AGENT_IND)
{

	
	const auto lmd_checkKey = [&]()->int
	{
		
		if (Key[KEY_INPUT_UP])
			return UP;
		
		if (Key[KEY_INPUT_DOWN])
			return DOWN;

		if (Key[KEY_INPUT_RIGHT])
			return RIGHT;

		if (Key[KEY_INPUT_LEFT])
			return LEFT;

		return 0;
		
	};


	Agent* agent_now = AGENT;
	
	const int x_now = agent_now[AGENT_IND].get_xpoint();

	const int y_now = agent_now[AGENT_IND].get_ypoint();

	static int move_x = 0;
	 
	static int move_y = 0;



	switch (lmd_checkKey())
	{
	case UP:
		move_y = -1;
		break;

	case DOWN:
		move_y = 1;
		break;

	case LEFT:
		move_x = -1;
		break;

	case RIGHT:
		move_x = 1;
		break;

	
	default:
		assert(!"ERROR!");
		break;
	}

	if (x_now + move_x < 0 || x_now + move_x >= stage[0].size())
	{
		move_x = 0;
	}
	if (y_now + move_y < 0 || y_now + move_y >= stage.size())
	{
		move_y = 0;
	}

	printfDx("%d,%d\n", move_x + x_now, move_y + y_now);


	renderer.Draw_color(x_now + move_x, y_now + move_y, CHOSEN);

	
	if (Key[KEY_INPUT_M])
	{
		agent_now->move(x_now + move_x, y_now + move_y, stage);
		inputting++;
		return;
		
	}
	else if (Key[KEY_INPUT_R])
	{
		agent_now->remove(x_now + move_x, y_now + move_y, stage);
		inputting++;
		return;
		
	}
	else if (Key[KEY_INPUT_S])
	{
		agent_now->deploy(x_now + move_x, y_now + move_y, agent_now[AGENT_IND].get_color(), stage);
		inputting++;
		return;
	}

	
	return;

		
}

void Game::mainLoop()
{
	switch (mode)
	{
	case INIT:
		this->make_stage();
		
		mode = PLAYING;
		break;

	case PLAYING:
		
		
		switch (inputting)
		{
		case 0:
			this->Turn(agent_Blue, 0);
			break;

		case 1:
			this->Turn(agent_Blue, 1);
			break;

		case 2:
			this->Turn(agent_Yellow, 0);
			break;

		case 3:
			this->Turn(agent_Yellow, 1);
			break;

		case 4://入力終了
			this->score_calcurate(BLUE);//なんかに入力して表示
			this->score_calcurate(YELLOW);

			

			++turn_num;
			//設定したターン数を過ぎたらmodeをENDに
			break;

		default:
			assert(!"ERROR");
			break;
		}

		
		this->Draw_update();//更新
		

		break;

	case END://スコアとか表示してリトライ
		break;

	default:
		assert(!"ERROR!");
		break;
	}

}
