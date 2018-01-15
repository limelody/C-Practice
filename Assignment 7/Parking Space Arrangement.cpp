#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>

/*assume that there aren't more people on the add list than the number of
parking spaces available*/

using namespace std;

const int N_SPACES = 51;
//made arrray size 51 so that indices match with parking lot number
const int N_SPACES_TEMP = 50;
//arrays with add and remove data will only be 50, as only 50 parking spaces

//B
void current_parking(ifstream &fin, bool status[], string name[])
{
    bool status_temp = 0;
    string name_temp ="y";
    int park_num_temp = 0;

    for (int avail_space = 0; avail_space < N_SPACES; avail_space++)
    	name[avail_space] = "y";
//changes the name to "y" and then names will be over-written if space fills up

    while (fin >> status_temp >> name_temp >> park_num_temp
           && park_num_temp < N_SPACES)
    {
        status[park_num_temp] = status_temp;
        name[park_num_temp] = name_temp;
    }
}

//C
int read_files(ifstream &fin, bool status[], string name[])
{
   bool status_temp;
   string name_temp;

   int index = 0;
   while(fin >> status_temp >> name_temp && index < N_SPACES_TEMP)
   {
     	status[index] = status_temp;
     	name[index] = name_temp;
     	index++;
   }

    return index;
}

//D
void modify_remove(string name[], string name_remove)
{
    for(int index=0; index < N_SPACES; index++)
    {
        if (name_remove == name[index])
            name[index]= "y";
    }
}

//E
int find_first_space(string name[], bool space_status )
{
	int starting_point = 1; // staff

    if(space_status == false)
		starting_point = 26;

    int parking_spot = -1;
    for(int index = starting_point; index < N_SPACES && parking_spot == -1;
        index++)
    	if (name[index] == "y")
    		parking_spot = index;

    return parking_spot;
}

//F
bool assign_space(bool status[], string name[], string name_temp,
                  bool status_temp)
{
   int first_space = find_first_space(name, status_temp);

   if(first_space != -1)
   {
        name[first_space] = name_temp;
        status[first_space] = status_temp;
        return true;
   }

   return false;
}

//G
void optimize_staff(bool status[], string name[])
{
	for(int first_point = 26; first_point < N_SPACES; first_point++)
	{
		if(status[first_point]==true)
		{
			int first_found = find_first_space(name, true);
			if(first_found!=-1 && first_found<26)
			{
				string name_temp = name[first_point];
				modify_remove(name, name[first_point]);
				assign_space(status, name, name_temp, true);
			}
		}
	}
}

//H
void output_list(ofstream &fout, bool status[], string name[])
{
    for (int index = 1 ; index < N_SPACES; index++)
    {
    	if(name[index]!="y")
            fout << setw(4) << (int)status[index] << setw(20) << name[index]
                 << setw(4) << index << endl;
	}
}

int main()
{
	ifstream fin_current("parking_current.txt");
  	ifstream fin_add("parking_add.txt");
  	ifstream fin_remove("parking_remove.txt");

  	if (!fin_current || !fin_add || !fin_remove)
    {
      	cout << "File not found";
      	return EXIT_FAILURE;
    }

 	ofstream fout("parking_updated.txt");

 	bool status_masterlist [N_SPACES] = {0},
         status_temp_add   [N_SPACES_TEMP] = {0},
         status_temp_remove[N_SPACES_TEMP] = {0};

  	string name_masterlist [N_SPACES],
           name_temp_add   [N_SPACES_TEMP],
           name_temp_remove[N_SPACES_TEMP];

  	current_parking(fin_current, status_masterlist, name_masterlist);

  	int number_remove = read_files(fin_remove, status_temp_remove,
                                   name_temp_remove),
        number_add = read_files(fin_add, status_temp_add, name_temp_add);


	// Remove people
	for(int counter = 0; counter < number_remove; counter++)
        modify_remove(name_masterlist, name_temp_remove[counter]);


  	// Optimize people
  	optimize_staff(status_masterlist, name_masterlist);

	// Add people
	for(int new_people = 0; new_people < number_add; new_people++)
        assign_space(status_masterlist, name_masterlist,
                     name_temp_add[new_people], status_temp_add[new_people]);

	output_list(fout, status_masterlist, name_masterlist);

	fout.close();
	fin_current.close();
    fin_add.close();
    fin_remove.close();

	return EXIT_SUCCESS;
}

