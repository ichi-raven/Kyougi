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
	
	void rnd_score_set(std::vector<std::vector<int> >&rndin, const int R_NUM, const int C_NUM);//�����_���X�R�A�����A��L�֐��ł����g��Ȃ�

	void score_calcurate(const int COLOR);//�v�Z�܂Ƃ�

	bool check_within(const int R, const int C, const int COLOR);//�ċA�֐��A��L�v�Z�֐����ŌĂяo��

	void Turn(Agent* AGENT);//�ړ��A�P���A�ݒu�܂Ƃ�

	void Update();//���ꂼ��̃G�[�W�F���g�ɂ��čX�V���A���Ԃ�����X�L�b�v�����肷��

	void Draw_update();//�A�b�v�f�[�g����ꏊ�̂ݕ`��

	void mainLoop();//�܂Ƃ�

private:

	int mode;//���C�����[�v���������邩�̕���p

	Agent agent[4];//�G�[�W�F���g4�l�A�O��l����

	std::vector<std::vector<Trout> > stage;//Trout�^2�����z��

	std::vector<std::vector<bool> > checkstage;//���̍ċA�ɂ����Ă��łɖK��Ă����false, �K��Ă��Ȃ����true

	std::vector<std::vector<bool> > decisionstage;//true�ň͂܂�Ă���Afalse�ň͂܂�ĂȂ�

	Draw renderer;//�`�揈���p

	int blue_score;//�X�R�A�i�[

	int yellow_score;//����

	int turn_num;//�߂����^�[����

	int limit_turn;//���E�^�[��

	int inputting;//�����͂��Ă���G�[�W�F���g

};