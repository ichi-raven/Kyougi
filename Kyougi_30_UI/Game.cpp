 #include"Headers_include.hpp"
#include"Constant_expressions.hpp"





Game::Game()
{



	for (int i = 0; i < 8; ++i)
	{
		stage.emplace_back();
		for (int j = 0; j < 10; ++j)
		{
			stage[i].emplace_back();
		}
	}


	for (auto &S : stage)
		for (auto &s : S)
		{
			s.set_state(NONE);
			s.set_score(1);
		}

	agent_Blue[0].set_color(BLUE);
	agent_Blue[0].set_point(1, 1);

	agent_Blue[1].set_color(BLUE);
	agent_Blue[1].set_point(5, 1);

	agent_Yellow[0].set_color(YELLOW);
	agent_Yellow[0].set_point(1, 5);

	agent_Yellow[1].set_color(YELLOW);
	agent_Yellow[1].set_point(5, 5);

	mode = INIT;

	inputting = 0;

}

void Game::make_stage()
{

	renderer.set_coodinate(stage.size(), stage[0].size());

	renderer.Draw_line();

	int r = 0, c = 0;
	for (const auto S : stage)
	{
		for (const auto s : S)
		{
	

			renderer.Draw_number(r, c, stage[r][c].get_score());

			
			++c;
		}
		
		++r;
		c = 0;
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
				check_within(index_R, index_C, COLOR);

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







bool Game::check_within(const int R, const int C, const int COLOR)
{
	const auto lmd_isRightPoint = [&](int _R, int _C)->bool
	{
		if (_R <= 0 || _R >= stage.size() || _C <= 0 || _C >= stage[0].size())
			return false;
		else 
			return true;
	};


	if (lmd_isRightPoint(R, C) && !checkstage[R][C])//壁に接していて自色のマスじゃなかったら
		return false;

	checkstage[R][C] = false;//すでに来た場所ということでチェック入れる

	if (checkstage[R - 1][C] && lmd_isRightPoint(R - 1, C))//上が自色のマスもしくはすでに来た場所じゃなかったら
	{
		if (!check_within(R - 1, C, COLOR))//上について同じように調べる
	   		return false;
	}
	if (checkstage[R + 1][C] && lmd_isRightPoint(R + 1, C))//下が同上
	{
		if (!check_within(R, C + 1, COLOR))//下について調べる
			return false;
	}
	if (checkstage[R][C + 1] && lmd_isRightPoint(R, C + 1))//右が同上
	{
		if (!check_within(R - 1, C, COLOR))//右について調べる
			return false;
	}
	if (checkstage[R][C - 1] && lmd_isRightPoint(R, C - 1))//左が同上
	{
		if (!check_within(R+ 1, C, COLOR))//左について調べる
			return false;
	}

	//ここから下に来れるということは四隅が壁じゃないまま詰まったマス = 囲まれている

	if (COLOR == BLUE)
	{
		if(stage[R][C].get_state() == INSIDE_Y)
			stage[R][C].set_state(INSIDE_BOTH);
		else
			stage[R][C].set_state(INSIDE_B);

	}
	else if (COLOR == YELLOW)
	{
		if (stage[R][C].get_state() == INSIDE_B)
			stage[R][C].set_state(INSIDE_BOTH);
		else
			stage[R][C].set_state(INSIDE_Y);
	}


	return true;
	



}


void Game::Draw_update()
{
	renderer.Draw_line();//ステージの線描画

	int r = 0, c = 0;



	for (const auto S : stage)//ステージの色がある場所描画
	{
		
		for (const auto s : S)
		{
			renderer.Draw_color(r, c, s.get_state());
			renderer.Draw_number(r, c, stage[r][c].get_score());

			++c;
		}
		++r;
		c = 0;
	}



	for (int i = 0; i < 2; ++i)//エージェント描画
	{
		renderer.Draw_Agent(agent_Blue[i].get_raw_point(), agent_Blue[i].get_col_point(), agent_Blue[i].get_color());

		renderer.Draw_Agent(agent_Yellow[i].get_raw_point(), agent_Yellow[i].get_col_point(), agent_Yellow[i].get_color());
	}


	



	


	//スコア実装		



}

void Game::Turn(Agent* AGENT, const int AGENT_IND)
{

	
	const auto lmd_checkKey = [&]()->int
	{
		
		if (Key[KEY_INPUT_UP] == 1)
			return UP;
		
		if (Key[KEY_INPUT_DOWN] == 1)
			return DOWN;

		if (Key[KEY_INPUT_RIGHT] == 1)
			return RIGHT;

		if (Key[KEY_INPUT_LEFT] == 1)
			return LEFT;

		return STOP;
		
	};


	Agent* agent_now = AGENT;

	const int enemy_color = (agent_now[AGENT_IND].get_color() == BLUE ? YELLOW : BLUE);
	
	const int r_now = agent_now[AGENT_IND].get_raw_point();

	const int c_now = agent_now[AGENT_IND].get_col_point();

	const int another_r_now = agent_now[(AGENT_IND - 1) * -1].get_raw_point();

	const int another_c_now = agent_now[(AGENT_IND - 1) * -1].get_col_point();

	static int move_r = 0;
	 
	static int move_c = 0;

	printfDx("an, %d : %d\n", another_r_now, another_c_now);

	switch (lmd_checkKey())
	{
	case UP:
		--move_r;
		break;

	case DOWN:
		++move_r;
		break;

	case LEFT:
		--move_c;
		break;

	case RIGHT:
		++move_c;
		break;

	case STOP:
		break;
	
	default:
		assert(!"ERROR!");
		break;
	}

	//printfDx("%d,%d\n", move_x + r_now, move_c + c_now);

	if (move_r < 0)
		move_r = -1;
	if (move_r > 0)
		move_r = 1;

	if (move_c < 0)
		move_c = -1;
	if (move_c > 0)
		move_c = 1;

	if (c_now + move_c < 0 || c_now + move_c >= stage[0].size())
	{
		move_c = 0;
	}
	if (r_now + move_r < 0 || r_now + move_r >= stage.size())
	{
		move_r = 0;
	}



	renderer.Draw_color(r_now + move_r, c_now + move_c, CHOSEN);

	const int state_trout_now = stage[r_now + move_r][c_now + move_c].get_state();

	
	if (Key[KEY_INPUT_M] == 1 && state_trout_now != enemy_color && !(another_r_now == r_now + move_r && another_c_now == c_now + move_c))
	{
		agent_now[AGENT_IND].move(r_now + move_r, c_now + move_c, stage);
		inputting++;
		move_r = 0;
		move_c = 0;
		return;
		
	}
	else if (Key[KEY_INPUT_R] == 1 && state_trout_now == enemy_color)
	{
		agent_now[AGENT_IND].remove(r_now + move_r, c_now + move_c, stage);
		inputting++;
		move_r = 0;
		move_c = 0;
		return;
		
	}
	else if (Key[KEY_INPUT_D] == 1 && state_trout_now != BLUE && state_trout_now != YELLOW)
	{
		agent_now[AGENT_IND].deploy(r_now + move_r, c_now + move_c, agent_now[AGENT_IND].get_color(), stage);
		inputting++;
		move_r = 0;
		move_c = 0;
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

		//assert(!"Came");
	
		break;

	case PLAYING:
		this->Draw_update();//更新
		
		
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

			inputting = 0;

			++turn_num;
			//設定したターン数を過ぎたらmodeをENDに
			break;

		default:
			assert(!"ERROR");
			break;
		}

		
		

		break;

	case END://スコアとか表示してリトライ
		break;

	default:
		assert(!"ERROR!");
		break;
	}

}
