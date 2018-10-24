#pragma once
#include"Agent.hpp"
#include"Draw.hpp"
#include"Trout.hpp"
#include<vector>
#include<array>

typedef std::vector<std::vector<Trout> > Stage;

class Game
{
public:
	Game();

	void make_stage();//ステージをファイル読み込んで作成

	void score_calcurate(const int COLOR);//計算まとめ

	bool check_within(const int R, const int C, const int COLOR);//再帰関数、上記計算関数内で呼び出す

	void undo();//ターン内で1手戻す

	void Turn_undo();//ターンを戻す

	void Turn_redo();//戻したターンを進める

	void write_turn_log();//ログ(ファイル名)に現在のTurn:X B1:(x1,y1) B2(x2,y2) Y1(x3,y3) Y2(x4,y4)\n と書き出す 

	void Turn(Agent* AGENT);//移動、撤去、設置まとめ

	void Update();//それぞれのエージェントについて更新し、かぶったらスキップしたりする

	void Draw_update();//アップデートする場所のみ描画

	void mainLoop();//まとめ

private:

	int mode;//メインループが何をするかの分岐用

	std::array<Agent, 4>  agent;//エージェント4人、前二人が青

	std::vector<std::vector<std::array<Agent, 4> > >agent_history;//エージェントの座標等をブランチ的に記録する

	Stage stage;//Trout型2次元配列

	std::vector<std::vector<Stage> > stage_history;//盤面をブランチ的に記録していく

	int now_branch;//現在のブランチ

	std::vector<std::vector<bool> > checkstage;//その再帰においてすでに訪れていればfalse, 訪れていなければtrue

	std::vector<std::vector<bool> > decisionstage;//trueで囲まれている、falseで囲まれてない

	Draw renderer;//描画処理用

	int blue_score;//スコア格納

	int yellow_score;//同上

	int turn_num;//過ぎたターン数

	int inputting;//今入力しているエージェント

	const std::string data_filename;

	const std::string log_filename;

};