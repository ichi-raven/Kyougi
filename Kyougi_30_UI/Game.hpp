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

	int score_calcurate(const int COLOR);//�v�Z�܂Ƃ�

	bool check_within(const int X, const int Y, const int COLOR);//�ċA�֐��A��L�v�Z�֐����ŌĂяo��

	void Turn(const int COLOR);

	void Draw_update();

private:
	Agent agent_Blue[2];//�G�[�W�F���g��l

	Agent agent_Yellow[2];//����

	std::vector<std::vector<Trout> > stage;//Trout�^2�����z��

	std::vector<std::vector<bool> > checkstage;//�`�F�b�N�p�A���score_calcurate�ł����g��Ȃ�

	Draw drawer;//�`�揈���p

};