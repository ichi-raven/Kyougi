#pragma once
#include<vector>


class Trout;


class Agent
{
	Agent(int STATE);//��ԕϐ��̂����F���������̂��g��

	void set_point(int IND_R, int IND_C);

	void move(int direction, std::vector<std::vector<Trout> > &stage);//�����w�肵�Ĉړ��A������constexpr

	void remove(int direction, std::vector<std::vector<Trout> > &stage);//�����w�肵�ēP���A������ry


private:

	int state;//�F

	int index_raw;//�s��index

	int index_col;//��index


};