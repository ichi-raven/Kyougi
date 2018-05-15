#pragma once






class Trout
{
public:
	//Trout();

	void set_score(const int number);

	int get_score() const;

	void set_state(const int STATE);
	
	int get_state() const;

	void set_Istate(const int INSIDE_STATE);

	int get_Istate() const;

private:

	int score;//マスに書かれるであろう数値

	int state;//色、constexpxで指定する

	int inside_state;//どの色の内側にあるか


};