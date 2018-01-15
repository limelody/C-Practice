//Vishvam Mazumdar and Melody Li

//					Question 1
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

const int N_ROWS = 50, N_COLUMNS = 25, MAX_N_CACHES=25;


void readElevations(ifstream &fin, int elevations[][N_COLUMNS])
{
    for (int vertical = 0; vertical < N_ROWS; vertical++)
    {
        for (int horizontal = 0; horizontal < N_COLUMNS; horizontal++)
        {
            fin >> elevations[horizontal][vertical];
        }
    }
}

int readGeocaches(ifstream &fin, int coordinates[MAX_N_CACHES][2])
//2 as there is x and y coord
{
    int num_caches = 0;
    bool is_cache = 0;

    for (int vertical = 0; vertical < N_ROWS; vertical++)
    {
        for (int horizontal = 0; horizontal < N_COLUMNS; horizontal++)
        {
            fin >> is_cache;
            if (is_cache)
            {
                coordinates[num_caches][0] = horizontal;
                coordinates[num_caches][1] = vertical;
                num_caches ++;
            }
        }
    }

    return num_caches;
}



double getEnergyToLocation(int start[2], int end[2],
							int elevations[N_ROWS][N_COLUMNS] )
{
	//100 is the number of meters between points horizontally
	//or vertically
	int deltaX = 100*(end[0] - start[0]),
		deltaY = 100*(end[1]-start[1]),
		deltaZ = elevations[end[0]][end[1]] -
				 elevations[start[0]][start[1]];

	return sqrt(deltaX*deltaX + deltaY*deltaY + deltaZ*deltaZ*49);
	//49 = 7^2 and it takes 7 times the amount of energy to travel
	//	in the z direction than in the x and y
}

//returns location of next coord in array
bool findNextGeocache (int coordinates[MAX_N_CACHES][2],
						int elevations[N_ROWS][N_COLUMNS],
						int start_coord[2], int & next_coord,
						int num_caches)
{
	int  least_energy_location = -1;
	double min_energy = 1e100; //greater than possible energy values

	for(int cache = 0; cache<num_caches; cache++)
	{
		if(coordinates[cache][0]>=0&&coordinates[cache][1]>=0)
		{
			double energy_to_location = getEnergyToLocation(
				start_coord, coordinates[cache], elevations);

			cout<<coordinates[cache][0]<<", "<<coordinates[cache][1]<<": "<<energy_to_location<<endl;

			if(energy_to_location<min_energy)
			{
				min_energy = energy_to_location;
				least_energy_location = cache;
			}
		}
	}

	cout<<endl;

	if(least_energy_location > -1)
	{
		next_coord = least_energy_location;
		return true;
	}
	return false;
}

void plotPath (int elevations[N_ROWS][N_COLUMNS],
			int coordinates[MAX_N_CACHES][2]
			, int plane_path[MAX_N_CACHES][2], int num_caches)
{
	int start_coord[2] = {0}, next_coord = 0;
	for(int destination = 0; destination< num_caches; destination++)
	{
		findNextGeocache(coordinates,elevations,start_coord,
			next_coord,num_caches);

		plane_path[destination][0] = coordinates[next_coord][0];
		plane_path[destination][1] = coordinates[next_coord][1];

		start_coord [0] = coordinates[next_coord][0];
		start_coord [1] = coordinates[next_coord][1];

		coordinates[next_coord][0] = -1;
		coordinates[next_coord][1] = -1;

	}
}

void outputPath(ofstream & fout_plane_path,
				int plane_path[MAX_N_CACHES][2], int num_caches)
{
	fout_plane_path<<"Plane route: (x, y) - where (0, 0) represents "
					<<"North-West Corner \n(0, 0)"<<endl;
	for(int destination = 0; destination< num_caches; destination++)
	{
		fout_plane_path<<"("<<plane_path[destination][0]<<", "<<
			plane_path[destination][1]<<")"<<endl;
	}
}

int main()
{
	//input and output files
    ifstream fin_elevations("elevations.txt");
    ifstream fin_geocaches("caches.txt");
    ofstream fout_plane_path("plane_path.txt");

    if (!fin_elevations||!fin_geocaches)
    {
        cout << "Unable to open one of the files";
        return EXIT_FAILURE;
    }

	//arrays
    int elevations [N_ROWS][N_COLUMNS] = {0};
    int coordinates [MAX_N_CACHES][2] = {0};//2 is for x and y coords
    int plane_path[MAX_N_CACHES][2] = {0};

	//fill with -1s to represent empty coordinates
	for(int i=0; i<MAX_N_CACHES; i++)
	{
		coordinates[i][0] = -1;
		coordinates[i][1] = -1;
	}

	//read in files
    readElevations(fin_elevations, elevations);
	int num_caches = readGeocaches(fin_geocaches, coordinates);

	//fill in the plane_path array
	plotPath(elevations, coordinates, plane_path, num_caches);

	//output to file
	outputPath(fout_plane_path, plane_path, num_caches);

	fin_elevations.close();
	fin_geocaches.close();
	fout_plane_path.close();

    return EXIT_SUCCESS;
}
