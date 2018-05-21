#pragma once
#include<vector>


class Trout;


class Agent
{
public:
	//Agent();

	void set_point(const int R, const int C);

	void set_direction(const int MOVE_R, const int MOVE_C);

	int get_raw_point() const;

	int get_raw_dir() const;

	int get_col_point() const;

	int get_col_dir() const;

	void set_doing(const int DO);

	int get_doing() const;

	bool isSameTarget(const Agent& ANOTHER) const;

	bool isSamePoint(const Agent& ANOTHER) const;

	void set_color(const int STATE);

	int get_color() const;

	void move(std::vector<std::vector<Trout> > &stage);//移動

	void remove(std::vector<std::vector<Trout> > &stage);//撤去

	void deploy(std::vector<std::vector<Trout> > &stage);//設置


private:

	int color;//色

	int mR;//現在地行

	int mC;//現在地列

	int move_R;//移動先の行への差

	int move_C;// 同列

	int Do;//このターン何をするか


};