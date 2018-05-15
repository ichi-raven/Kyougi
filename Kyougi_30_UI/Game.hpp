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

	bool check_within(const int R, const int C, const int COLOR);//再帰関数、上記計算関数内で呼び出す

	void Turn(Agent* AGENT, const int AGENT_IND);//移動、撤去、設置まとめ

	void Draw_update();//アップデートする場所のみ描画

	void mainLoop();//まとめ

private:

	int mode;//メインループが何をするかの分岐用

	Agent agent_Blue[2];//エージェント二人

	Agent agent_Yellow[2];//同上

	std::vector<std::vector<Trout> > stage;//Trout型2次元配列

	std::vector<std::vector<bool> > checkstage;//その再帰においてすでに訪れていればfalse, 訪れていなければtrue

	std::vector<std::vector<bool> > decisionstage;//trueで囲まれている、falseで囲まれてない

	Draw renderer;//描画処理用

	int blue_score;//スコア格納

	int yellow_score;//同上

	int turn_num;//過ぎたターン数

	int inputting;//今入力しているエージェント

};