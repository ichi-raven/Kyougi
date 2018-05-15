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

	bool check_within(const int R, const int C, const int COLOR);//�ċA�֐��A��L�v�Z�֐����ŌĂяo��

	void Turn(Agent* AGENT, const int AGENT_IND);//�ړ��A�P���A�ݒu�܂Ƃ�

	void Draw_update();//�A�b�v�f�[�g����ꏊ�̂ݕ`��

	void mainLoop();//�܂Ƃ�

private:

	int mode;//���C�����[�v���������邩�̕���p

	Agent agent_Blue[2];//�G�[�W�F���g��l

	Agent agent_Yellow[2];//����

	std::vector<std::vector<Trout> > stage;//Trout�^2�����z��

	std::vector<std::vector<bool> > checkstage;//���̍ċA�ɂ����Ă��łɖK��Ă����false, �K��Ă��Ȃ����true

	std::vector<std::vector<bool> > decisionstage;//true�ň͂܂�Ă���Afalse�ň͂܂�ĂȂ�

	Draw renderer;//�`�揈���p

	int blue_score;//�X�R�A�i�[

	int yellow_score;//����

	int turn_num;//�߂����^�[����

	int inputting;//�����͂��Ă���G�[�W�F���g

};