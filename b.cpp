#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int main(void) {

	fflush(stdin);
	fflush(stdout);

	freopen("km3net_reference.detx","r",stdin);
	
	int num;
	cin >> num;

	string version;
	cin >> version;

	float x, y;
	cin >> x >> y;

	string t, m, n;
	cin >> t >> m >> n;

	float s1, s2, s3;
	cin >> s1 >> s2 >> s3;

	// Number of strings in the detector
	int num_strings;
	cin >> num_strings;

	vector <int> DOM_ID, MOD_ID, DOM_IN_MOD, PMT_IN_DOM;
	vector <vector <pair <int, vector <float> > > > data;

	// 61*x + x = 128339 => x is approx 2070
	for(int i = 0; i < 2070; i++) {

		/*
		// DOM - DOM_ID
		// MOD - MOD_ID
		// DIM - No. of DOM within MOD
		// PID - No. of PMTs within this DOM
		*/
		int DOM, MOD, DIM, PID;
		cin >> DOM >> MOD >> DIM >> PID;

		DOM_ID.push_back(DOM);
		MOD_ID.push_back(MOD);
		DOM_IN_MOD.push_back(DIM);
		PMT_IN_DOM.push_back(PID);

		vector <pair <int, vector<float> > > sub_data;

		// 60 entries for each DOM
		for(int j = 0; j < PID; j++) {

			// index of each entry
			int index; 
			cin>>index;

			vector<float> temp_data;

			// Postion and Directions for each particle
			float x, y, z, x_d, y_d, z_d;
			cin >> x >> y >> z >> x_d >> y_d >> z_d;
			temp_data.push_back(x);
			temp_data.push_back(y);
			temp_data.push_back(z);
			temp_data.push_back(x_d);
			temp_data.push_back(y_d);
			temp_data.push_back(z_d);

			// Calibration Constant
			float calibration_const;
			cin >> calibration_const;
			temp_data.push_back(calibration_const);

			pair <int, vector<float> > p (index, temp_data);

			sub_data.push_back(p);

		}

		data.push_back(sub_data);
	}

	fclose(stdin);

	float d_tp = 5.f * 2.f * 3.1415927 / (360.f * 360.f);
	cout<<d_tp<<endl;

}