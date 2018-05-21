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
	
	void rnd_score_set(std::vector<std::vector<int> >&rndin, const int R_NUM, const int C_NUM);//ランダムスコア生成、上記関数でしか使わない

	void score_calcurate(const int COLOR);//計算まとめ

	bool check_within(const int R, const int C, const int COLOR);//再帰関数、上記計算関数内で呼び出す

	void Turn(Agent* AGENT);//移動、撤去、設置まとめ

	void Update();//それぞれのエージェントについて更新し、かぶったらスキップしたりする

	void Draw_update();//アップデートする場所のみ描画

	void mainLoop();//まとめ

private:

	int mode;//メインループが何をするかの分岐用

	Agent agent[4];//エージェント4人、前二人が青

	std::vector<std::vector<Trout> > stage;//Trout型2次元配列

	std::vector<std::vector<bool> > checkstage;//その再帰においてすでに訪れていればfalse, 訪れていなければtrue

	std::vector<std::vector<bool> > decisionstage;//trueで囲まれている、falseで囲まれてない

	Draw renderer;//描画処理用

	int blue_score;//スコア格納

	int yellow_score;//同上

	int turn_num;//過ぎたターン数

	int limit_turn;//限界ターン

	int inputting;//今入力しているエージェント

};