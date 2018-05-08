#pragma once
#include"Agent.hpp"
#include"Draw.hpp"
#include"Trout.hpp"
#include<vector>

class Game
{
public:
	Game();

	void make_stage();

	int score_calcurate(const int COLOR);//計算まとめ

	bool check_within(const int X, const int Y, const int COLOR);//再帰関数、上記計算関数内で呼び出す

	void Turn(const int COLOR);

	void Draw_update();

private:
	Agent agent_Blue[2];//エージェント二人

	Agent agent_Yellow[2];//同上

	std::vector<std::vector<Trout> > stage;//Trout型2次元配列

	std::vector<std::vector<bool> > checkstage;//チェック用、主にscore_calcurateでしか使わない

	Draw drawer;//描画処理用

};