#pragma once
#include<vector>


class Trout;


class Agent
{
	Agent(int STATE);//��ԕϐ��̂����F���������̂��g��

	void set_point(int IND_X, int IND_Y);

	void move(int direction, std::vector<std::vector<Trout> > &stage);//�����w�肵�Ĉړ��A������constexpr

	void remove(int direction, std::vector<std::vector<Trout> > &stage);//�����w�肵�ēP���A������ry

	void deploy(int direction, int color, std::vector<std::vector<Trout> > &stage);//�����w�肵�Đݒu�A�����A�F��ry


private:

	int state;//�F

	int index_x;//���ݒnx��index

	int index_y;//���ݒny��index


};