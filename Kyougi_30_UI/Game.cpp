#include"Headers_include.hpp"
#include"Constant_expressions.hpp"


Game::Game()
{
	for(auto &S: stage)
		for (auto &s : S)
		{
			s.set_state(NONE);
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

	if ((Y <= 0 || Y >= stage.size() || X <= 0 || X >= stage[0].size()) && !checkstage[Y][X])//壁に接していて自色のマスじゃなかったら
		return false;

	checkstage[Y][X] = false;//すでに来た場所ということでチェック入れる

	if (checkstage[Y - 1][X])//上が自色のマスもしくはすでに来た場所じゃなかったら
	{
		if (!check_within(X, Y - 1, COLOR))//上について同じように調べる
	   		return false;
	}
	if (checkstage[Y + 1][X])//下が同上
	{
		if (!check_within(X, Y + 1, COLOR))//下について調べる
			return false;
	}
	if (checkstage[Y][X + 1])//右が同上
	{
		if (!check_within(X - 1, Y, COLOR))//右について調べる
			return false;
	}
	if (checkstage[Y][X - 1])//左が同上
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



