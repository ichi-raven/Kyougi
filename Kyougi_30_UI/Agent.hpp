#pragma once
#include<vector>


class Trout;


class Agent
{
	//Agent();

	void set_point(const int X, const int Y);

	int get_xpoint() const;

	int get_ypoint() const;

	void set_color(const int STATE);

	int get_color() const;

	void move(int direction, std::vector<std::vector<Trout> > &stage);//�����w�肵�Ĉړ��A������constexpr

	void remove(int direction, std::vector<std::vector<Trout> > &stage);//�����w�肵�ēP���A������ry

	void deploy(int direction, int COLOR, std::vector<std::vector<Trout> > &stage);//�����w�肵�Đݒu�A�����A�F��ry


private:

	int color;//�F

	int mX;//���ݒnx

	int mY;//���ݒny


};