TSplineFit* IIndexRev_Aluminium(Bool_t todraw = kFALSE,Bool_t infile = kFALSE,Bool_t firstinfile = kFALSE)
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
//   IIndexRev_Aluminium
//
//   Imaginary part of index of refraction for aluminium function of wavelength
//
//   Source : Hanbook of optical constants
//
//  Old f_imalu.C
//
{
  Int_t k1;
  Int_t k2 = -100;
  k1 = TClassTable::GetID("TSplineFit");
  if (k1<0) k2 = gSystem->Load("libSplineFit");
  const Int_t M = 29;
  const Int_t m = 4;
  Int_t i;
  Double_t sig[M];
  TSplineFit *IIndexRevAlu;
  Double_t x[M] = { 300.0,   317.9,   335.1,   350.0,   364.7,   387.5,   413.3,   442.8,   459.2,
    495.9,   506.1,   527.6,   550.0,   563.6,   590.4,   604.8,   635.8,   652.6,
    688.8,   708.5,   750.0,   774.9,   825.0,   850.0,   875.0,   900.0,   925.0,
    950.0,   991.9 };
  Double_t y[M] = { 3.61,    3.84,    4.06,    4.24,    4.43,    4.71,    5.02,    5.38,    5.58,
    6.03,    6.15,    6.42,    6.69,    6.85,    7.15,    7.31,    7.65,    7.82,
    8.21,    8.39,    8.62,    8.60,    8.31,    8.22,    8.18,    8.30,    8.49,
    8.88,    9.49 };
  for (i=0;i<M;i++) sig[i] = 0.03;
  IIndexRevAlu = new TSplineFit("IIndexRev_Aluminium","Im.  part of refraction index | Pure aluminium",
    4,M,m,x,y,sig,kTRUE,0.0,kFALSE,10.0,300.0,1000.0);
  IIndexRevAlu->SetSource("Hanbook of optical constants");
  IIndexRevAlu->SetMacro("IIndexRev_Aluminium.C");
  IIndexRevAlu->SetXLabel("wavelength [nm]");
  IIndexRevAlu->SetVLabel("imaginary part index");
  if (todraw) {
    IIndexRevAlu->SetDefaultLabels();
    IIndexRevAlu->DrawFit();
    IIndexRevAlu->Print();
  }
  if (infile) {
    if (firstinfile) IIndexRevAlu->UpdateFile(kTRUE);
    else             IIndexRevAlu->UpdateFile(kFALSE);
  }
  return IIndexRevAlu;
}
