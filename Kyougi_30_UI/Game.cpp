#include"Headers_include.hpp"
#include"Constant_expressions.hpp"


extern int Key[256];


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
	agent_Blue[1].set_color(BLUE);
	agent_Yellow[0].set_color(YELLOW);
	agent_Yellow[1].set_color(YELLOW);

	mode = INIT;
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
	for (int i = 0; i < 2; ++i)//エージェント描画
	{
		renderer.Draw_Agent(agent_Blue[i].get_xpoint(), agent_Blue[i].get_ypoint(), BLUE);

		renderer.Draw_Agent(agent_Yellow[i].get_xpoint(), agent_Yellow[i].get_ypoint(), YELLOW);
	}


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


	//スコア実装		



}

void Game::Turn(Agent* AGENT, const int AGENT_IND)
{
	const auto lmd_checkKey = [&]()->int
	{
		if (Key[KEY_INPUT_UP] && Key[KEY_INPUT_LEFT])
			return UP_LEFT;
		else if (Key[KEY_INPUT_UP] && Key[KEY_INPUT_RIGHT])
			return UP_RIGHT;
		else if (Key[KEY_INPUT_UP])
			return UP;

		if (Key[KEY_INPUT_DOWN] && Key[KEY_INPUT_LEFT])
			return DOWN_LEFT;
		else if (Key[KEY_INPUT_DOWN] && Key[KEY_INPUT_RIGHT])
			return DOWN_RIGHT;
		else if (Key[KEY_INPUT_UP])
			return DOWN;

		if (Key[KEY_INPUT_RIGHT])
			return RIGHT;

		if (Key[KEY_INPUT_LEFT])
			return LEFT;

		return 0;
		
	};


	Agent* agent_now = AGENT;

	const int direction = lmd_checkKey();//判定ラムダの結果入れる

	

		int chosen_x = agent_now[AGENT_IND].get_xpoint();
		int chosen_y = agent_now[AGENT_IND].get_ypoint();



		switch (direction)
		{
		case UP:
			--chosen_y;
			break;

		case DOWN:
			++chosen_y;
			break;

		case LEFT:
			--chosen_x;
			break;

		case RIGHT:
			++chosen_x;
			break;

		case UP_LEFT:
			--chosen_y;
			--chosen_x;
			break;

		case UP_RIGHT:
			--chosen_y;
			++chosen_x;
			break;

		case DOWN_LEFT:
			++chosen_y;
			--chosen_x;
			break;

		case DOWN_RIGHT:
			++chosen_y;
			++chosen_x;
			break;

		default:
			assert(!"ERROR!");
			break;
		}

		

		renderer.Draw_color(chosen_x, chosen_y, CHOSEN);

		bool isNotMycolor = stage[chosen_y][chosen_x].get_state() != agent_now->get_color();

		if (Key[KEY_INPUT_M])
		{
			agent_now->move(direction, stage);
			
		}
		else if (Key[KEY_INPUT_R] && isNotMycolor)
		{
			agent_now->remove(direction, stage);
			
		}
		else if (Key[KEY_INPUT_S] && !isNotMycolor)
		{
			agent_now->deploy(direction, agent_now->get_color(), stage);
		}

	


		
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
		assert(0);//バグはここ以降

		this->Turn(agent_Blue, 0);
		this->Turn(agent_Blue, 1);
		
		this->Turn(agent_Yellow, 0);
		this->Turn(agent_Yellow, 1);

		this->score_calcurate(BLUE);
		this->score_calcurate(YELLOW);

		this->Draw_update();

		++turn_num;
		//設定したターン数を過ぎたらmodeをENDに

		break;

	case END://スコアとか表示してリトライ
		break;

	default:
		assert(!"ERROR!");
		break;
	}

}
