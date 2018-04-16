#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream.h>

using namespace std;

class Ram{

	private:
		int used, total, percent, avialable;

	public:
		Ram(){
			used=total=percent=avialable=00;
		}

		int get_used(){ return used; }
		int get_total(){ return total; }
		int get_used_percent(){ return percent; }

		void read(){
			ifstream myfile("/proc/meminfo");
			string line1, line2, line3;
			if(myfile.is_open()){
				getline(myfile, line1);
				getline(myfile, line2);
				getline(myfile,line3);
			}
		  myfile.close();
		  total=extractInteger(line1);
		  avialable=extractInteger(line3);

		}

		int extractInteger(string line){
			char buffer[7];
			int j=0;
			for(int i=0; i<line.length(); i++){
				if(line[i]>=48 && line[i]<=57){
					buffer[j]=line[i];
					j++;
				}
			}
			int number=atoi(buffer);
		}

};