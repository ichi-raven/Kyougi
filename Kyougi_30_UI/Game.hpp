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

	void score_calcurate(const int COLOR);

	void Turn(const int COLOR);

	void Draw_update();

private:
	Agent agent_Blue[2];//エージェント二人

	Agent agent_Yellow[2];//同上

	std::vector<std::vector<Trout> > stage;//Trout型2次元配列

	Draw drawer;//描画処理用

};