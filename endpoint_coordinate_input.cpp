#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <fstream>
using namespace std;

//int start;

int main(int argc, char *argv[]) // argc ~ the number of command line inputs into argv
                                 // argv ~ an array of string inputs:
                                 //   ./main <end_Latitude_deg> <end_Lat_min> <end_Lat_sec> <end_long_deg> ... <end_long_sec> 
{
    float end_Lat_coord[] = { 0, 0, 0 };
    float end_Long_coord[] = { 0, 0, 0 };
    float dd_end_Lat;
    float dd_end_Long;
   // degree minute GPS input
    if (argc == 7){  
        for (int k = 1; k < argc; ++k ){
            if (k <=3){
                end_Lat_coord[k - 1] = atof(argv[k]); // converts from string to float
            }
            else{
                end_Long_coord[k - 4] = atof(argv[k]);
            }
        }
        if (end_Lat_coord[0] < 0){
            dd_end_Lat = end_Lat_coord[0] - end_Lat_coord[1]/60 - end_Lat_coord[2]/3600;
        }
        else {
            dd_end_Lat = end_Lat_coord[0] + end_Lat_coord[1]/60 + end_Lat_coord[2]/3600;
        }
        if (end_Long_coord[0] < 0){
            dd_end_Long = end_Long_coord[0] - end_Long_coord[1]/60 - end_Long_coord[2]/3600;  
        }
        else {
            dd_end_Long = end_Long_coord[0] + end_Long_coord[1]/60 + end_Long_coord[2]/3600;
        }
        
        cout << dd_end_Lat << " " << dd_end_Long << "\n";
    }
    // degree minute GPS input 
    else if (argc == 5){
        for (int k = 1; k < argc; ++k ){
            if (k <=2){
                end_Lat_coord[k - 1] = atof(argv[k]); // converts from string to float
            }
            else{
                end_Long_coord[k - 3] = atof(argv[k]);
            }
        }
        if (end_Lat_coord[0] < 0){
            dd_end_Lat = end_Lat_coord[0] - end_Lat_coord[1]/60;
        }
        else {
            dd_end_Lat = end_Lat_coord[0] + end_Lat_coord[1]/60; 
        }
        if (end_Long_coord[0] < 0){
            dd_end_Long = end_Long_coord[0] - end_Long_coord[1]/60; 
        }
        else {
            dd_end_Long = end_Long_coord[0] + end_Long_coord[1]/60;
        }
        cout << dd_end_Lat << " " << dd_end_Long << "\n";
    }
    // degree GPS input
    else if(argc == 3){
        dd_end_Lat = atof(argv[1]);
        dd_end_Long = atof(argv[2]);
        cout << dd_end_Lat << " " << dd_end_Long << "\n";
    }
     // have to check that the command line inputs have been put in
    else {
        exit(1);
    }
    cout << argc << "\n";
    for (int n = 1; n <= 3; ++n){
        cout << end_Lat_coord[n - 1] << " ";
    }
    cout << "\n";
    for (int i = 1; i <= 3; ++i){
        cout << end_Long_coord[i - 1] << " ";
    }
    cout << "\n";

    // calculating distance between an initial and end gps point in decimal degrees
    /************************************************************************************************************************
    float dd_start_Lat;
    float dd_start_Long;
    // convert to radians
    dd_start_Lat_rad = dd_start_Lat * M_PI/180;
    dd_start_Long_rad = dd_start_Long * M_PI/180;
    dd_end_Lat_rad = dd_end_Lat * M_PI/180;
    dd_end_Long_rad = dd_end_Long * M_PI/180;
    // "haversine" formula to measure distance between two points (supposed to be good for short distances as well)
    float delt_Lat = dd_end_Lat_rad - dd_start_Lat_rad;
    float delt_Long = dd_end_Long_rad - dd_start_Long_rad;
    float a = sin(delt_Lat/2) * sin(delt_Lat/2) + cos(dd_start_Lat_rad) * cos(dd_end_Lat_rad) * (sin(delt_Long/2) * sin(delt_Long/2));
    float aa; = sqrt(a);
    float R = 6369970
    float D = 2 * R * asin(aa);
    *************************************************************************************************************************/
   
   // specifying specs for .yaml file
   float D = 325; // m
   float DD = D + 50; // distance to final location and 50 m radius around
   float pixel = 938;
   float Resol = DD/938; // meters
   float cell_size = 0.4;  // meters
   float num_cells = DD/cell_size;
   float origin[] = { 1582/2, 0, 0 };
   float occupied_thresh = 0.65;
   float free_thresh = 0.196;
   int negate = 0;
   // editting specs in Global_Map_Blank.yaml
   ofstream file("/home/catkin_ws/src/global_map/Maps/Global_Map_Blank.yaml");
   //ofstream file("Global_Map_Blank.yaml");
   file << "image: Global_Map_Blank.png" << endl;
   file << "resolution: " << Resol << endl;
   file << "origin: [" << origin[0] << " " << origin[1] << " " << origin[2] <<"]" << endl;
   file << "occupied_thresh: " << occupied_thresh << endl;
   file << "free_thresh: " << free_thresh << endl;
   file << "negate: " << negate << endl;
   file << "width: " << num_cells << endl << "height: " << num_cells << endl;
   

    return 0;
}

/*
start (int argc, char *argv[]){
    return 0;
}
*/