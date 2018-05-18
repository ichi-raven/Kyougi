#include"Headers_include.hpp"
#include"Constant_expressions.hpp"





Game::Game()
{


	mode = INIT;

	inputting = 0;

	turn_num = 1;

	limit_turn = get_rand(80, 120);

	blue_score = 0;
	yellow_score = 0;

}

void Game::make_stage()
{


	const int R_num = get_rand(9, 12);

	const int C_num = get_rand(9, 12);

	for (int r = 0; r < R_num; ++r)
	{
		stage.emplace_back();
		for (int c = 0; c < C_num; ++c)
		{
			stage[r].emplace_back();
		}
	}

	std::vector<std::vector<int> > score;

	rnd_score_set(score, R_num, C_num);

	for (int r = 0; r < stage.size(); ++r)
		for (int c = 0; c < stage[0].size(); ++c)
		{
			stage[r][c].set_state(NONE);
			stage[r][c].set_Istate(NONE);
			stage[r][c].set_score(score[r][c]);
		}

	const int agent_defR = get_rand(1, R_num / 2 - 1);

	const int agent_defC = get_rand(1, C_num / 2 - 1);

	agent_Blue[0].set_color(BLUE);
	agent_Blue[0].set_point(agent_defR, agent_defC);

	agent_Blue[1].set_color(BLUE);
	agent_Blue[1].set_point(R_num - agent_defR - 1, agent_defC);

	agent_Yellow[0].set_color(YELLOW);
	agent_Yellow[0].set_point(agent_defR, C_num - agent_defC - 1);

	agent_Yellow[1].set_color(YELLOW);
	agent_Yellow[1].set_point(R_num - agent_defR - 1, C_num - agent_defC - 1);




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

	//別にいらないけど行数,列数表示
	printfDx("R%d: C%d\n", stage.size(), stage[0].size() );

	
	
}

void Game::rnd_score_set(std::vector<std::vector<int> >&rndin, const int R_NUM, const int C_NUM)
{
	/* なんちゃって確率操作。余裕があれば書き直します */

	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rnd33(0, 16);
	std::uniform_int_distribution<> rnd25(-16, 0);
	std::uniform_int_distribution<> rnd17(0, 8);

	std::random_device R_bool;
	std::mt19937 mt2(R_bool());
	std::uniform_int_distribution<> r_bool(0, 10);


	rndin.resize(R_NUM);
	for (int a = 0; a < R_NUM; a++)
		rndin[a].resize(C_NUM);


	/* 負の数が少なめになるように色々いじっています。 */

	int i, j;

	for (i = 0; i < R_NUM; i++) {

		if (C_NUM % 2 == 0) {
			for (j = 0; j < C_NUM / 2; j++) {
				if (r_bool(mt2) == 0) {
					rndin[i][j] = rnd25(mt);
					rndin[i][C_NUM - (j + 1)] = rndin[i][j];
				}
				else {
					rndin[i][j] = rnd33(mt);
					rndin[i][C_NUM - (j + 1)] = rndin[i][j];
				}
			}
		}

		else {
			for (j = 0; j < C_NUM / 2; j++) {
				if (r_bool(mt2) == 0) {
					rndin[i][j] = rnd25(mt);
					rndin[i][C_NUM - (j + 1)] = rndin[i][j];
				}
				else {
					rndin[i][j] = rnd33(mt);
					rndin[i][C_NUM - (j + 1)] = rndin[i][j];
				}
			}


			if (r_bool(mt2) == 0)
				rndin[i][j] = rnd25(mt);
			else
				rndin[i][j] = rnd33(mt);

		}


	}


}


void Game::score_calcurate(const int COLOR)//色を渡すとその色の点数を返す
{

	const auto lmd_init_checkstage = [&]()//checkstage初期化
	{
		checkstage.clear();

		for (auto &S : stage)
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
	};

	const auto lmd_init_decisionstage = [&]()//decisionstage初期化
	{
		decisionstage.clear();

		for (auto &S : stage)
		{
			decisionstage.emplace_back();

			for (auto &s : S)
			{

				if (s.get_state() != COLOR)
					decisionstage.back().emplace_back(true);
				else
					decisionstage.back().emplace_back(false);

			}
		}
	};

	lmd_init_decisionstage();//この一回のみ


	lmd_init_checkstage();



	for (int index_R = 0; index_R < stage.size(); ++index_R)//探索開始
	{

		for (int index_C = 0; index_C < stage[0].size(); ++index_C)
		{

			const bool result = check_within(index_R, index_C, COLOR);

			if (checkstage[index_R][index_C])//判定終了時に未到達の点は
				continue;

			if(!result)
			{
				for (int r = 0; r < stage.size(); ++r)
					for (int c = 0; c < stage[0].size(); ++c)
						if (!checkstage[r][c])//すでに来たマスについて全部falseをdecisionstageに代入
							decisionstage[r][c] = false;
			}
			else
			{
				for (int r = 0; r < stage.size(); ++r)//囲まれていた場合
					for (int c = 0; c < stage[0].size(); ++c)
						if (!checkstage[r][c])//すでに来たマスは囲まれているのでtrueを格納
							decisionstage[r][c] = true;
			}



			lmd_init_checkstage();//checkstage初期化



		}
	}

	//何色の内部なのかここで判定

	for (int r = 0; r < stage.size(); ++r)
		for (int c = 0; c < stage[0].size(); ++c)
		{
			if (stage[r][c].get_state() == COLOR)//自身のマス
				continue;

			if (!decisionstage[r][c])//囲まれてない
			{
				if (COLOR == BLUE)
					if (stage[r][c].get_Istate() == INSIDE_Y)
						continue;

				if (COLOR == YELLOW)
					if (stage[r][c].get_Istate() == INSIDE_B)
						continue;


				stage[r][c].set_Istate(NONE);
				continue;
			}

			if (COLOR == BLUE)//色付け部分
			{
				if (stage[r][c].get_Istate() == INSIDE_Y)
					stage[r][c].set_Istate(INSIDE_BOTH);
				else
					stage[r][c].set_Istate(INSIDE_B);

			}
			else if (COLOR == YELLOW)
			{
				if (stage[r][c].get_Istate() == INSIDE_B)
					stage[r][c].set_Istate(INSIDE_BOTH);
				else
					stage[r][c].set_Istate(INSIDE_Y);
			}
			
		}
		
	
	//ここからスコア計算

	int score = 0;

	for(const auto S : stage)
		for (const auto s : S)
		{
			if (s.get_state() == COLOR)
			{
				score += s.get_score();
				continue;
			}

			if(COLOR == BLUE)
				if (s.get_Istate() == INSIDE_B || s.get_Istate() == INSIDE_BOTH)
					score += abs(s.get_score());
				
			if (COLOR == YELLOW)
				if (s.get_Istate() == INSIDE_Y || s.get_Istate() == INSIDE_BOTH)
					score += abs(s.get_score());
		}

	if (COLOR == BLUE)
		blue_score = score;
	else if (COLOR == YELLOW)
		yellow_score = score;
	else
		assert(!"Color isn't right!");

}







bool Game::check_within(const int R, const int C, const int COLOR)
{
	const auto lmd_isRightPoint = [&](int _R, int _C)->bool
	{
		if (_R <= 0 || _R >= stage.size() - 1 || _C <= 0 || _C >= stage[0].size() - 1)
			return false;
		else
			return true;
	};




	if (!checkstage[R][C])//すでに来た場所ならtrueを返す
		return true;
	
	checkstage[R][C] = false;//すでに来た場所ということでチェック入れる
	

	if (!lmd_isRightPoint(R, C))//壁に接していたら
		return false;

	if (stage[R][C].get_state() == COLOR)//自身の色のマスならtrueを返す
		return true;


	//if (!lmd_isRightPoint(R, C) || !lmd_isRightPoint(R - 1, C) || !lmd_isRightPoint(R + 1, C) || !lmd_isRightPoint(R, C - 1) || !lmd_isRightPoint(R, C + 1))//壁に接していたら
	//	return false;







	if (checkstage[R - 1][C])//上が自色のマスもしくはすでに来た場所じゃなかったら
		if (!check_within(R - 1, C, COLOR))//上について同じように調べる
	   		return false;

	if (checkstage[R + 1][C])//下が同上
		if (!check_within(R + 1, C, COLOR))//下について調べる
			return false;

	if (checkstage[R][C + 1])//右が同上
		if (!check_within(R, C + 1, COLOR))//右について調べる
			return false;

	if (checkstage[R][C - 1])//左が同上
		if (!check_within(R, C - 1, COLOR))//左について調べる
			return false;


	//ここから下に来れるということは四隅が壁じゃないまま詰まったマス = 囲まれている

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
			renderer.Draw_color(r, c, s.get_state(), s.get_Istate());
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
	renderer.Draw_Util(turn_num, limit_turn, blue_score, yellow_score);




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

	//printfDx("an, %d : %d\n", another_r_now, another_c_now);

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




	const int state_trout_now = stage[r_now + move_r][c_now + move_c].get_state();

	const int inside_state_trout_now = stage[r_now + move_r][c_now + move_c].get_Istate();

	
	renderer.Draw_color(r_now + move_r, c_now + move_c, CHOSEN, inside_state_trout_now);
	
	if ((Key[KEY_INPUT_Z] == 1  || Key[KEY_INPUT_M] == 1) && state_trout_now != enemy_color && !(another_r_now == r_now + move_r && another_c_now == c_now + move_c) )
	{
		agent_now[AGENT_IND].move(r_now + move_r, c_now + move_c, stage);
		agent_now[AGENT_IND].deploy(r_now + move_r, c_now + move_c, agent_now[AGENT_IND].get_color(), stage);
		inputting++;
		move_r = 0;
		move_c = 0;
		return;
		
	}
	else if ((Key[KEY_INPUT_C] == 1 || Key[KEY_INPUT_R] == 1) && state_trout_now != NONE && (move_c != 0 || move_r != 0) )
	{
		agent_now[AGENT_IND].remove(r_now + move_r, c_now + move_c, stage);
		inputting++;
		move_r = 0;
		move_c = 0;
		return;
		
	}
	
	
	if (state_trout_now != BLUE && state_trout_now != YELLOW)
		agent_now[AGENT_IND].deploy(r_now, c_now, agent_now[AGENT_IND].get_color(), stage);

	
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
			this->score_calcurate(BLUE);
			this->score_calcurate(YELLOW);


			inputting = 0;

			++turn_num;
			if (turn_num >= limit_turn)//設定したターン数を過ぎたらmodeをENDに
				mode = END;
		
			break;

		default:
			assert(!"ERROR");
			break;
		}

		
		

		break;

	case END://リトライ
		mode = INIT;
		break;

	default:
		assert(!"ERROR!");
		break;
	}

}
