#include "iostream"
#include "vector"
#include "queue"
#include "algorithm"
using namespace std;
class user
{
public:
	string name;
	int points;
	bool selected;
	bool mission_done;

	user()
	{
		name = "undefined";
		points = 0;
		selected = false;
		mission_done = false;
	}

	user(string name, int points)
	{
		this->name = name;
		this->points = points;
	}

	void increase_points()
	{
		points = points + 10;
	}

	void true_selected()
	{
		selected = true;
	}

	void false_selected()
	{
		selected = false;
	}
};

class region
{
public:
	string Name;
	vector<string> problems;
	int counter = 0;

	void region_name(string Name)
	{
		this->Name = Name;
	}
	void add_problem(string x)
	{
		problems.push_back(x);
	}
	bool mission(user x, int n)
	{
		srand(time(0));
		int fate = rand() % 2;
		int i = n - 1;
		if (fate==0)
		{
			cout << x.name << " has accomplished the mission" << endl;
			problems.erase(problems.begin() + i);
			return true;
		}
		else if (fate==1)
		{
			cout << x.name << " has not accomplished the mission" << endl;
			return false;
		}
	}
	void print_problems()
	{
		cout << endl;
		for (int i = 0; i < problems.size(); i++)
		{
			cout << i + 1 << ") " << problems[i]<<endl;
		}
	}
};

class application
{
public:
	vector<user> data;
	int max_points, rank=1;

	application()
	{
		max_points = 0;
	}
	void insert_member(user x)
	{
		data.push_back(x);
	}
	void print_leaderboard()
	{
		cout << "" << endl;																															
		cout << "Leaderboard" << endl;
		cout << "-------------" << endl;
		vector<user> temp = data;		
		while (temp.empty()!=true)
		{
			user max;
			int eraseindex=0;
			for (int i = 0; i < temp.size(); i++)
			{
				if (temp[i].points>=max.points)
				{
					max = temp[i];
					eraseindex = i;
				}
			}
			cout << rank << ") " << max.name <<" | "<< max.points << endl;
			if (eraseindex==0)
			{
				temp.erase(temp.begin());
			}
			else
			{
				temp.erase(temp.begin() + (eraseindex));
			}
			temp.shrink_to_fit();
			rank++;
		}
		rank = 1;
	}

	void printusers()
	{
		for (int i = 0; i < data.size(); i++)
		{
			cout << i + 1 << ") " << data[i].name << endl;
		}
	}

	void incpointstt(int index)
	{
		data[index - 1].increase_points();
	}
};

int main()
{
	region world;
	world.Name = "sidi gaber";
	world.add_problem("trees");
	world.add_problem("garbage");
	world.add_problem("walls");
	int x=1;
	application app;
	cout << "Welcome to EGYGREEN" << endl;
	cout << "Please choose" << endl;
	while (x!=0)
	{
		string names;
		int incpoints;
		cout << endl;
		cout << "1) Insert participant" << endl;
		cout << "2) Increase participant's points" << endl;
		cout << "3) Print leaderboard" << endl;
		cout << "4) assign member to solve problem" << endl;
		cout << "5) view problems" << endl;
		cout << endl;
		cin >> x;
		if (x==1)
		{
			cout << "enter name: ";
			cin >> names;
			user t;
			t.name = names;
			app.insert_member(t);
			cout << endl;
		}
		else if (x==2)
		{
			app.printusers();
			cout << "Choose member to increase points by 10: ";
			cin >> incpoints;
			app.incpointstt(incpoints);
			cout << endl;
		}
		else if (x==3)
		{
			app.print_leaderboard();
		}
		else if (x==4)
		{
			bool result;
			int m;
			int p;
			app.printusers();
			cout << "please choose participant to assign ";
			cin >> m;
			cout << endl;
			world.print_problems();
			cout << "please choose problem too assign too ";
			cin >> p;
			result=world.mission(app.data[m - 1], p);
			if (result==true)
			{
				app.incpointstt(m);
			}
		}
		else if (x == 5)
		{
			world.print_problems();
		}
	}
}
