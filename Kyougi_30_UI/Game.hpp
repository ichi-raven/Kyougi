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

	void make_stage();//�X�e�[�W���t�@�C���ǂݍ���ō쐬

	void score_calcurate(const int COLOR);//�v�Z�܂Ƃ�

	bool check_within(const int R, const int C, const int COLOR);//�ċA�֐��A��L�v�Z�֐����ŌĂяo��

	void undo();//�^�[������1��߂�

	void Turn_undo();//�^�[����߂�

	void Turn_redo();//�߂����^�[����i�߂�

	void write_turn_log();//���O(�t�@�C����)�Ɍ��݂�Turn:X B1:(x1,y1) B2(x2,y2) Y1(x3,y3) Y2(x4,y4)\n �Ə����o�� 

	void Turn(Agent* AGENT);//�ړ��A�P���A�ݒu�܂Ƃ�

	void Update();//���ꂼ��̃G�[�W�F���g�ɂ��čX�V���A���Ԃ�����X�L�b�v�����肷��

	void Draw_update();//�A�b�v�f�[�g����ꏊ�̂ݕ`��

	void mainLoop();//�܂Ƃ�

private:

	int mode;//���C�����[�v���������邩�̕���p

	std::array<Agent, 4>  agent;//�G�[�W�F���g4�l�A�O��l����

	std::vector<std::vector<std::array<Agent, 4> > >agent_history;//�G�[�W�F���g�̍��W�����u�����`�I�ɋL�^����

	Stage stage;//Trout�^2�����z��

	std::vector<std::vector<Stage> > stage_history;//�Ֆʂ��u�����`�I�ɋL�^���Ă���

	int now_branch;//���݂̃u�����`

	std::vector<std::vector<bool> > checkstage;//���̍ċA�ɂ����Ă��łɖK��Ă����false, �K��Ă��Ȃ����true

	std::vector<std::vector<bool> > decisionstage;//true�ň͂܂�Ă���Afalse�ň͂܂�ĂȂ�

	Draw renderer;//�`�揈���p

	int blue_score;//�X�R�A�i�[

	int yellow_score;//����

	int turn_num;//�߂����^�[����

	int inputting;//�����͂��Ă���G�[�W�F���g

	const std::string data_filename;

	const std::string log_filename;

};