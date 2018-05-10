 #include"Headers_include.hpp"
#include"Constant_expressions.hpp"





Game::Game()
{

	

	for (int i = 0; i < 8; ++i)
	{
		stage.emplace_back();
		for (int j = 0; j < 10; ++j)
		{
			stage[i].emplace_back();
		}
	}


	for(auto &S: stage)
		for (auto &s : S)
		{
			s.set_state(NONE);
			s.set_score(1);
		}

	agent_Blue[0].set_color(BLUE);
	agent_Blue[0].set_point(1, 1);

	agent_Blue[1].set_color(BLUE);
	agent_Blue[1].set_point(5, 1);

	agent_Yellow[0].set_color(YELLOW);
	agent_Yellow[0].set_point(1, 5);

	agent_Yellow[1].set_color(YELLOW);
	agent_Yellow[1].set_point(5, 5);

	mode = INIT;

	inputting = 0;
}

void Game::make_stage()
{

	renderer.set_coodinate(stage[0].size(), stage.size());

	renderer.Draw_line();

	int i = 0, j = 0;
	for (const auto S : stage)
	{
		for (const auto s : S)
		{
	

			renderer.Draw_number(j, i, stage[i][j].get_score());

			
			++j;
		}
		
		++i;
		j = 0;
	}

	
	
}


int Game::score_calcurate(const int COLOR)//�F��n���Ƃ��̐F�̓_����Ԃ�
{
	
	for (auto &S : stage)//checkstage�쐬
	{
		checkstage.emplace_back();

		for (auto &s : S)
		{

			if (s.get_state() != COLOR)
				checkstage.back().emplace_back(true);
			else
				checkstage.back().emplace_back(false);

		}
	}
			
	for (auto i = checkstage.begin(); i < checkstage.end(); ++i)//���g�̐F����Ȃ����T���}�X�T���ĒT���J�n
	{
		const int index_R = i - checkstage.begin();

		for (auto j = checkstage[index_R].begin(); j < checkstage[index_R].end(); ++j)
		{
			const int index_C = j - checkstage[index_R].begin();

			if (checkstage[index_R][index_C])
			{
				check_within(index_C, index_R, COLOR);

			}
		}
	}
		
	//��������X�R�A�v�Z

	int score = 0;

	for(const auto S : stage)
		for (const auto s : S)
		{
			score += s.get_score();
		}

	return score;

}







bool Game::check_within(const int X, const int Y, const int COLOR)
{
	const auto lmd_isRightPoint = [&](int _X, int _Y)->bool
	{
		if (_Y <= 0 || _Y >= stage.size() || _X <= 0 || _X >= stage[0].size())
			return false;
		else 
			return true;
	};


	if (lmd_isRightPoint(X, Y) && !checkstage[Y][X])//�ǂɐڂ��Ă��Ď��F�̃}�X����Ȃ�������
		return false;

	checkstage[Y][X] = false;//���łɗ����ꏊ�Ƃ������ƂŃ`�F�b�N�����

	if (checkstage[Y - 1][X] && lmd_isRightPoint(X, Y - 1))//�オ���F�̃}�X�������͂��łɗ����ꏊ����Ȃ�������
	{
		if (!check_within(X, Y - 1, COLOR))//��ɂ��ē����悤�ɒ��ׂ�
	   		return false;
	}
	if (checkstage[Y + 1][X] && lmd_isRightPoint(X, Y + 1))//��������
	{
		if (!check_within(X, Y + 1, COLOR))//���ɂ��Ē��ׂ�
			return false;
	}
	if (checkstage[Y][X + 1] && lmd_isRightPoint(X + 1, Y))//�E������
	{
		if (!check_within(X - 1, Y, COLOR))//�E�ɂ��Ē��ׂ�
			return false;
	}
	if (checkstage[Y][X - 1] && lmd_isRightPoint(X - 1, Y))//��������
	{
		if (!check_within(X + 1, Y, COLOR))//���ɂ��Ē��ׂ�
			return false;
	}

	//�������牺�ɗ����Ƃ������Ƃ͎l�����ǂ���Ȃ��܂܋l�܂����}�X = �͂܂�Ă���

	if (COLOR == BLUE)
	{
		if(stage[Y][X].get_state() == INSIDE_Y)
			stage[Y][X].set_state(INSIDE_BOTH);
		else
			stage[Y][X].set_state(INSIDE_B);

	}
	else if (COLOR == YELLOW)
	{
		if (stage[Y][X].get_state() == INSIDE_B)
			stage[Y][X].set_state(INSIDE_BOTH);
		else
			stage[Y][X].set_state(INSIDE_Y);
	}


	return true;
	



}


void Game::Draw_update()
{
	renderer.Draw_line();//�X�e�[�W�̐��`��

	int i = 0, j = 0;




	for (const auto S : stage)//�X�R�A�\��
	{
		for (const auto s : S)
		{


			renderer.Draw_number(j, i, stage[i][j].get_score());


			++j;
		}

		++i;
		j = 0;
	}
	i = 0, j = 0;

	for (const auto S : stage)//�X�e�[�W�̐F������ꏊ�`��
	{
		
		for (const auto s : S)
		{
			renderer.Draw_color(j, i, s.get_state());

			++j;
		}
		++i;
		j = 0;
	}



	for (int i = 0; i < 2; ++i)//�G�[�W�F���g�`��
	{
		renderer.Draw_Agent(agent_Blue[i].get_xpoint(), agent_Blue[i].get_ypoint(), agent_Blue[i].get_color());

		renderer.Draw_Agent(agent_Yellow[i].get_xpoint(), agent_Yellow[i].get_ypoint(), agent_Yellow[i].get_color());
	}


	



	


	//�X�R�A����		



}

void Game::Turn(Agent* AGENT, const int AGENT_IND)
{

	
	const auto lmd_checkKey = [&]()->int
	{
		
		if (Key[KEY_INPUT_UP] == 1)
			return UP;
		
		if (Key[KEY_INPUT_DOWN] == 1)
			return DOWN;

		if (Key[KEY_INPUT_RIGHT] == 1)
			return RIGHT;

		if (Key[KEY_INPUT_LEFT] == 1)
			return LEFT;

		return STOP;
		
	};


	Agent* agent_now = AGENT;
	
	const int x_now = agent_now[AGENT_IND].get_xpoint();

	const int y_now = agent_now[AGENT_IND].get_ypoint();

	static int move_x = 0;
	 
	static int move_y = 0;



	switch (lmd_checkKey())
	{
	case UP:
		--move_x;
		break;

	case DOWN:
		++move_x;
		break;

	case LEFT:
		--move_y;
		break;

	case RIGHT:
		++move_y;
		break;

	case STOP:
		break;
	
	default:
		assert(!"ERROR!");
		break;
	}

	//printfDx("%d,%d\n", move_x + x_now, move_y + y_now);

	if (move_y < 0)
		move_y = -1;
	if (move_y > 0)
		move_y = 1;

	if (move_x < 0)
		move_x = -1;
	if (move_x > 0)
		move_x = 1;

	if (x_now + move_x < 0 || x_now + move_x >= stage[0].size())
	{
		move_x = 0;
	}
	if (y_now + move_y < 0 || y_now + move_y >= stage.size())
	{
		move_y = 0;
	}



	renderer.Draw_color(x_now + move_x, y_now + move_y, CHOSEN);

	
	if (Key[KEY_INPUT_M] == 1)
	{
		agent_now[AGENT_IND].move(x_now + move_x, y_now + move_y, stage);
		inputting++;
		move_x = 0;
		move_y = 0;
		return;
		
	}
	else if (Key[KEY_INPUT_R] == 1 && stage[x_now + move_x][y_now + move_y].get_state())
	{
		agent_now[AGENT_IND].remove(x_now + move_x, y_now + move_y, stage);
		inputting++;
		move_x = 0;
		move_y = 0;
		return;
		
	}
	else if (Key[KEY_INPUT_S] == 1)
	{
		agent_now[AGENT_IND].deploy(x_now + move_x, y_now + move_y, agent_now[AGENT_IND].get_color(), stage);
		inputting++;
		move_x = 0;
		move_y = 0;
		return;
	}

	
	return;

		
}

void Game::mainLoop()
{
	switch (mode)
	{
	case INIT:
		this->make_stage();
		
		mode = PLAYING;
		break;

	case PLAYING:
		this->Draw_update();//�X�V
		
		printfDx("%d\n", inputting);
		switch (inputting)
		{
		case 0:
			this->Turn(agent_Blue, 0);
			break;

		case 1:
			this->Turn(agent_Blue, 1);
			break;

		case 2:
			this->Turn(agent_Yellow, 0);
			break;

		case 3:
			this->Turn(agent_Yellow, 1);
			break;

		case 4://���͏I��
			//this->score_calcurate(BLUE);//�Ȃ񂩂ɓ��͂��ĕ\��
			//this->score_calcurate(YELLOW);

			inputting = 0;

			++turn_num;
			//�ݒ肵���^�[�������߂�����mode��END��
			break;

		default:
			assert(!"ERROR");
			break;
		}

		
		

		break;

	case END://�X�R�A�Ƃ��\�����ă��g���C
		break;

	default:
		assert(!"ERROR!");
		break;
	}

}
