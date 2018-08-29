TSplineFit* PhotoEl_BGO(Bool_t todraw = kFALSE,Bool_t infile = kFALSE,Bool_t firstinfile = kFALSE)
//
// Arguments:
//
//  todraw       : true if the fit is to be drawn
//  infile       : true if the fit is to be put in file SplineFitDB.rdb
//  firstinfile  : if true, [BE CAREFUL: RISK OF LOOSING FILE SplineFitDB.rdb ]
//                 delete all fits present in file SplineFitDB.rdb and place
//                 this fit as the first fit in a new file SplineFitDB.rdb
//                 default false !!!
// All defaults for arguments correspond to the case where one calls this CINT
//macro from within a Litrani CINT macro to define a needed fit, instead of trying
//to find it in the database file SplineFitDB.rdb using TSplineFit::FindFit()
//
//   Photo-Electric Effect Cross Section for Bi4Ge3O12
//
//   Source: NIST http://physics.nist.gov/PhysRefData/Xcom/Text/XCOM.html
//
{
  Int_t k1;
  Int_t k2 = -100;
  k1 = TClassTable::GetID("TSplineFit");
  if (k1<0) k2 = gSystem->Load("libSplineFit");
  const Int_t M = 80;
  Int_t i;
  TSplineFit *PE_BGO;
  Double_t x[M] = { 0.001000, 0.001103, 0.001217, 0.001217, 0.001232, 0.001248, 0.001248, 0.001328, 0.001414, 0.001414, 0.001500, 0.002000, 0.002580, 0.002580, 0.002633, 0.002688, 0.002688, 0.003000, 0.003177, 0.003177, 0.003427, 0.003696, 0.003696, 0.003845, 0.003999, 0.003999, 0.004000, 0.005000, 0.006000, 0.008000, 0.010000, 0.011100, 0.011100, 0.012210, 0.013420, 0.013420, 0.015000, 0.015710, 0.015710, 0.016050, 0.016390, 0.016390, 0.020000, 0.030000, 0.040000, 0.050000, 0.060000, 0.080000, 0.090530, 0.090530, 0.100000, 0.150000, 0.200000, 0.300000, 0.400000, 0.500000, 0.600000, 0.800000, 1.000000, 1.022000, 1.250000, 1.500000, 2.000000, 2.044000, 3.000000, 4.000000, 5.000000, 6.000000, 7.000000, 8.000000, 9.000000, 10.000000, 11.000000, 12.000000, 13.000000, 14.000000, 15.000000, 16.000000, 18.000000, 20.000000};

  Double_t y[M] = { 9684941.760000, 7890744.216000, 6433864.088000, 7580329.416000, 7532732.480000, 7497552.136000, 8105965.144000, 7207831.656000, 6413169.768000, 6678057.064000, 5883395.176000, 3056551.064000, 1674584.374400, 3077245.384000, 3095870.272000, 3116564.592000, 4124377.976000, 3251077.672000, 2804080.360000, 3184855.848000, 2638525.800000, 2187389.624000, 2303277.816000, 2094265.184000, 1904084.383200, 1979204.764800, 1977963.105600, 1144188.952800, 726163.688800, 349527.064800, 196451.179760, 149454.379040, 211082.064000, 165182.062240, 129236.028400, 255781.795200, 189477.193920, 167396.354480, 221429.224000, 210461.234400, 199948.519840, 227016.690400, 136085.848320, 46582.914320, 21460.009840, 11684.013072, 7081.596304, 3199.341872, 2272.236336, 9941.551328, 7667.245560, 2650.942392, 1238.141166, 428.993254, 207.770973, 121.103161, 79.321329, 42.154330, 26.571507, 25.433319, 17.161800, 12.224135, 7.392011, 7.125054, 3.865699, 2.530915, 1.854211, 1.452741, 1.189510, 1.004709, 0.868334, 0.764034, 0.681050, 0.614414, 0.559367, 0.513219, 0.474107, 0.440375, 0.385535, 0.342491};
  PE_BGO = new TSplineFit("PhotoEl_BGO","Photo-Electric Cross Section | Bi4Ge3O12",18,M,x,y,0.001, 1.4);
  PE_BGO->SetSource("http://physics.nist.gov/PhysRefData/Xcom/Text/XCOM.html");
  PE_BGO->SetMacro("PhotoEl_BGO.C");
  PE_BGO->SetXLabel("Gamma Energy [MeV]");
  PE_BGO->SetVLabel("Cross Section x10+24 cm2");
  if (todraw) {
    PE_BGO->SetDefaultLabels();
    PE_BGO->DrawFit();
    gTwoPad->SetPadLogX(1);
    PE_BGO->Print();
  }
  if (infile) {
    if (firstinfile) PE_BGO->UpdateFile(kTRUE);
    else             PE_BGO->UpdateFile(kFALSE);
  }
  return PE_BGO;
}
