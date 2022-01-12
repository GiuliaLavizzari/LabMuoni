/* nel file di testo
1 colonna: treshold
2 colonna: singole
3 colonna: doppie
4 colonna: triple
top to bottom 
G1 M G2
t=300sec
G1 thr 82,3 HV 1050
G2 thr 72.2 HV 2050
*/

#include <iostream>
#include <cmath>
#include "TApplication.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TMath.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TStyle.h"
#include "TFitResult.h"
#include "TF1.h"
#include <vector>
#include <string>
#include <fstream>
#include "TH2D.h"
#include "TColor.h"

bool readData(std::string fileName, std::vector<float>& vec_thr, std::vector<float>& vec_s,  std::vector<float>& vec_d, std::vector<float>& vec_t)
{
  std::fstream myFile;
  
  myFile.open(fileName.c_str(),std::ios::in);
  //myFile.ignore(std::numeric_limits<std::streamsize>::max(), "\n");
  if (myFile.good() == false)
    {
      return false;
    }

  double val1, val2, val3, val4;
  while (true)
    {
      myFile >> val1 >> val2 >> val3 >> val4;
      if (myFile.eof() == true) break;
      vec_thr.push_back(val1);
      vec_s.push_back(val2);
      vec_d.push_back(val3);
      vec_t.push_back(val4); 
   
      
    }
  myFile.close();

  return true;
}

using namespace std;

int main (int argc, char** argv)
{

	gStyle->SetOptStat(0);
  //gStyle->SetOptFit(1110);

     if (argc < 7)
    {
      std::cout << "Insert from command line the two file names" << std::endl;
      std::cout << "\t./esercizio01 data.txt" << std::endl;
      return 1;
    }

  //prendo file in input e istanzio i vettori

	string fileInput  = argv[1];
	vector<float> vec_thr_HV_1000;
	vector<float> vec_s_HV_1000;
    vector<float> vec_d_HV_1000;
	vector<float> vec_t_HV_1000;
    vector<float> eff1000; 



	string fileInput1  = argv[2];
    vector<float> vec_thr_HV_950;
	vector<float> vec_s_HV_950;
    vector<float> vec_d_HV_950;
	vector<float> vec_t_HV_950;
    vector<float> eff950;

	string fileInput2  = argv[3];
	vector<float> vec_thr_HV_1020;
	vector<float> vec_s_HV_1020;
    vector<float> vec_d_HV_1020;
	vector<float> vec_t_HV_1020;
    vector<float> eff1020; 


    string fileInput3  = argv[4];
    vector<float> vec_thr_HV_1040;
	vector<float> vec_s_HV_1040;
    vector<float> vec_d_HV_1040;
	vector<float> vec_t_HV_1040;
    vector<float> eff1040;

   string fileInput4  = argv[5];
    vector<float> vec_thr_HV_970;
	vector<float> vec_s_HV_970;
    vector<float> vec_d_HV_970;
	vector<float> vec_t_HV_970;
    vector<float> eff970;

	string fileInput5 = argv[6];
    vector<float> vec_thr_HV_990;
	vector<float> vec_s_HV_990;
    vector<float> vec_d_HV_990;
	vector<float> vec_t_HV_990;
    vector<float> eff990;


	if (readData(fileInput, vec_thr_HV_1000, vec_s_HV_1000, vec_d_HV_1000, vec_t_HV_1000) == false)
		  {
		    std::cout << "Problem opening the file: " << fileInput.c_str() << std::endl;
		    return 1;
		  
		}

if (readData(fileInput1, vec_thr_HV_950, vec_s_HV_950, vec_d_HV_950, vec_t_HV_950) == false)
		  {
		    std::cout << "Problem opening the file: " << fileInput.c_str() << std::endl;
		    return 1;
		  
		}

	if (readData(fileInput2, vec_thr_HV_1020, vec_s_HV_1020, vec_d_HV_1020, vec_t_HV_1020) == false)
		  {
		    std::cout << "Problem opening the file: " << fileInput.c_str() << std::endl;
		    return 1;
		  
		}
if (readData(fileInput3, vec_thr_HV_1040, vec_s_HV_1040, vec_d_HV_1040, vec_t_HV_1040) == false)
		  {
		    std::cout << "Problem opening the file: " << fileInput.c_str() << std::endl;
		    return 1;
		  
		}


if (readData(fileInput4, vec_thr_HV_970, vec_s_HV_970, vec_d_HV_970, vec_t_HV_970) == false)
		  {
		    std::cout << "Problem opening the file: " << fileInput.c_str() << std::endl;
		    return 1;
		  
		}

if (readData(fileInput5, vec_thr_HV_990, vec_s_HV_990, vec_d_HV_990, vec_t_HV_990) == false)
		  {
		    std::cout << "Problem opening the file: " << fileInput.c_str() << std::endl;
		    return 1;
		  
		}



	gStyle->SetOptFit(1112);
 	TApplication* myApp = new TApplication("myApp", NULL, NULL);
 	TCanvas* c1 = new TCanvas("c1","c1",0,0,700,500);
 	
    for(int i=0;i<vec_thr_HV_1020.size();i++) {
    eff1020.push_back(vec_t_HV_1020.at(i)/vec_d_HV_1020.at(i));
    cout<<" thr 1020 "<< vec_thr_HV_1020.at(i)<< "  eff 1020  "<< eff1020.at(i)<<endl;
	}
    
    cout<<"--------------"<<endl;
	for(int i=0;i<vec_thr_HV_1000.size();i++) {
    eff1000.push_back(vec_t_HV_1000.at(i)/vec_d_HV_1000.at(i));
    cout<<" thr 1000 "<< vec_thr_HV_1000.at(i)<< "  eff 1000  "<< eff1000.at(i)<<endl;
	}

    cout<<"--------------"<<endl;

	for(int i=0;i<vec_thr_HV_950.size();i++) {
    	eff950.push_back(vec_t_HV_950.at(i)/vec_d_HV_950.at(i));
    	cout<<" thr 950 "<< vec_thr_HV_950.at(i)<< "  eff 950  "<< eff950.at	(i)<<endl;
	}
 cout<<"--------------"<<endl;

	for(int i=0;i<vec_thr_HV_1040.size();i++) {
    	eff1040.push_back(vec_t_HV_1040.at(i)/vec_d_HV_1040.at(i));
    	cout<<" thr 1040 "<< vec_thr_HV_1040.at(i)<< "  eff 1040 "<< eff1040.at	(i)<<endl;
	}
 cout<<"--------------"<<endl;
	for(int i=0;i<vec_thr_HV_970.size();i++) {
    	eff970.push_back(vec_t_HV_970.at(i)/vec_d_HV_970.at(i));
    	cout<<" thr 970"<< vec_thr_HV_970.at(i)<< "  eff 970 "<< eff970.at	(i)<<endl;
	}

for(int i=0;i<vec_thr_HV_990.size();i++) {
    	eff990.push_back(vec_t_HV_990.at(i)/vec_d_HV_990.at(i));
    	cout<<" thr 990 "<< vec_thr_HV_990.at(i)<< "  eff 990  "<< eff990.at	(i)<<endl;
	}




   TH2D EFF ("EFF", "EFF", 10, 940, 1050, 10, 50, 140);
     for ( int i = 0; i < 4; i++){
     EFF.Fill(950 ,vec_thr_HV_950.at(i), eff950.at(i));
     }
     for ( int i = 0; i < 5; i++){
     EFF.Fill(1000,vec_thr_HV_1000.at(i), eff1000.at(i));
     }
      for ( int i = 0; i < 5; i++){
     EFF.Fill(1020,vec_thr_HV_1020.at(i), eff1020.at(i));
     }

      for ( int i = 0; i < 6; i++){
     EFF.Fill(1040,vec_thr_HV_1040.at(i), eff1040.at(i));
     }

     for ( int i = 0; i < 4; i++){
     EFF.Fill(970,vec_thr_HV_970.at(i), eff970.at(i));
     }
for ( int i = 0; i < 6; i++){
     EFF.Fill(990,vec_thr_HV_990.at(i), eff990.at(i));
     }


     EFF.SetMaximum(1);
     EFF.SetMinimum(0.89);
    
    c1->cd();
	EFF.Draw("text colz0");
	EFF.SetTitle("Efficiency");
    EFF.GetXaxis()->SetTitle("HV (V)");
	EFF.GetYaxis()->SetTitle("Treshold (mV)");
	c1->Modified();
	c1->Update();
 
 myApp->Run();

 return 0;
}

