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
	Agent agent_Blue[2];//�G�[�W�F���g��l

	Agent agent_Yellow[2];//����

	std::vector<std::vector<Trout> > stage;//Trout�^2�����z��

	Draw drawer;//�`�揈���p

};