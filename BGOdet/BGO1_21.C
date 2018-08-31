{
time_t rawtime;
struct tm * timeinfo;
char buffer3 [80];
time (&rawtime);
timeinfo = localtime (&rawtime);
strftime (buffer3,80,"BGO_%H-%M_%d-%m-%Y",timeinfo);
char *name    = (char*) buffer3;
char *listing = (char*) buffer3;
char *upcom   = (char*)"Detector: general, all photons that hit Si are seen";
char *downcom = (char*)"MadeByGKosir";
char listing2[90];
strcpy (listing2,buffer3);
strcat (listing2,".root");
//char listing2 = buffer3+".root";
gROOT->ProcessLine(".x InitSLitrani.C(5,name,listing,upcom,downcom,kTRUE,kFALSE,kFALSE)");
//////////////////////////////////////////////////////////////////////////////////////
//Vprasalnik
Double_t avrgP, maxP, minP, sigmaP;
Bool_t niprivzeto;
Int_t k,n, nfot, nsims;
avrgP=0.4;
maxP=0.5;
minP=0.3;
sigmaP=0.05;
n=100;
nfot=1000;
nsims=1;
Bool_t vsebuje, privzeto2;
int ch;
const char* filepath;
std::string filepath1;
Int_t ran=1, num_det1, gam=1, vir_gam=1, own_conf[32], vir_spontan=1, st_izbr_det=32, Ncrta=555;
Double_t Xstart=-1.45, Xkonec=4.1, Zcrta=2.0, Ycrta= 0.439, Xcrta, dXcrta=0.01;
Xcrta=Xstart;
TVector3 source_spontan_vector2(Xcrta,Ycrta,Zcrta);
std::cout << "Z TLitGamma (1) ali TLitSpontan (2) ? " <<std::endl;	
Double_t Xsp=0,Ysp=0,Zsp=0;
std::cin >> gam;
if(gam==1) {
	std::cout << "Vir Gamma:  Valj (1) ali Ploskve-okoli (2) ali Ploskev-pod (3)? " <<std::endl;
	std::cin >> vir_gam;
	std::cout << "Privzete nastavitve:" << std::endl;
	std::cout << "Povprecje:	" << avrgP << " MeV/c" << std::endl;
	std::cout << "Max:		" << maxP << " MeV/c" << std::endl;
	std::cout << "Min:		" << minP << " MeV/c" << std::endl;
	std::cout << "St.dev:		" << sigmaP << " MeV/c" << std::endl;
	}
if(gam==2){
	std::cout << "TLitSpontan: Cel BGO (1) ali izbrana tocka (2), na izbrani visini (3) ali po crti v smeri x (4) ?" <<std::endl;
	std::cin >> vir_spontan;
	}
if(vir_spontan==2) {
	std::cout<< "Vnesi tocko izvora v kristalu (izhodisce je v srediscu BGO):" <<std::endl;
	std::cout<<"Vnesi X:" << std::endl;
	std::cin >> Xsp;
	std::cout<<"Vnesi Y:" << std::endl;
	std::cin >> Ysp;
	std::cout<<"Vnesi Z:" << std::endl;
	std::cin >> Zsp;
	TVector3 source_spontan_vector(Xsp,Ysp,Zsp);
	}
if(vir_spontan==3) {
	std::cout<<"Vnesi Z (0 je v srediscu kristala):" << std::endl;
	std::cin >> Zsp;
	std::cout<<"Vnesi stevilo tock:" << std::endl;
	std::cin >> Ncrta;
	char buffer5 [80];
	strftime (buffer5,80,"datafile_eff_x_y-%H-%M_%d-%m-%Y.dat",timeinfo);
	std::ofstream datafile3;
	  datafile3.open (buffer5);
	nsims=0;
	}
if(vir_spontan==4) {
	std::cout << "Visina crte :\t" << Zcrta << std::endl;
	std::cout << "Y crte :\tY = " << Ycrta << std::endl;
	std::cout << "Zacetek crte :\tX = " << Xstart << std::endl;
	std::cout << "Konec crte :\tX = "<< Xkonec << std::endl;
	std::cout << "Stevilo tock :\t"<< Ncrta << std::endl;
	std::cout << "Privzeto? (0:Da, 1:Ne) : " << std::endl;
	cin >> privzeto2;
	if(privzeto2) {
		std::cout<<"Vnesi visino crte: " << std::endl;
		std::cin >> Zcrta;
		std::cout <<"Vnesi Y: " << std::endl;
		std::cin >> Ycrta;
		std::cout<< "Vnesi zacetek crte (X koordinato) : "<<std::endl;
		std::cin >> Xstart;
		std::cout<< "Vnesi konec crte (X koordinato) : "<<std::endl;
		std::cin >> Xkonec;
		std::cout<< "Vnesi stevilo tock : "<<std::endl;
		std::cin >> Ncrta;
		Xcrta=Xstart;
		dXcrta=(Xkonec-Xstart) / (Double_t) Ncrta;
		TVector3 source_spontan_vector2(Xcrta,Ycrta,Zcrta);
		}
	char buffer4 [80];
	strftime (buffer4,80,"datafile_eff_x-%H-%M_%d-%m-%Y.dat",timeinfo);
	std::ofstream datafile2;
	  datafile2.open (buffer4);
	nsims=0;
	}
std::cout << "Meritev:\t" << n << std::endl;
std::cout << "Fotonov:\t" << nfot << std::endl;
std::cout << "Vseh fotonov:\t" << n*nfot << std::endl;
if(vir_spontan!=4) std::cout << "Kombinacij:\t" << nsims << std::endl;
if(vir_spontan==4) std::cout << "Stevilo tock:\t" << Ncrta << std::endl;
std::cout << "Stevilo detektorjev je nakljucno." << std::endl;
if ( gam==1 & vir_gam==1) std::cout << "Vir gamma zarkov je valj na koordinatah (0,0,-5)." << std::endl;
if ( gam==1 & vir_gam==2) std::cout << "Vir gamma zarkov so ploskve okoli detektorja." << std::endl;
if ( gam==1 & vir_gam==3) std::cout << "Vir gamma zarkov je ploskev pod detektorjem." << std::endl;
if (gam==2 & vir_spontan==1) std::cout << "TLitSpontan - cela prostornina kristala." <<std::endl;
if (gam==2 & vir_spontan==2) std::cout << "TLitSpontan - Tocka na koordinatah ("<< Xsp<<","<<Ysp<<","<<Zsp<<")." <<std::endl;
std::cout << "Privzeto? (0:Da, 1:Ne) : " << std::endl;
cin >> niprivzeto;
//ran=4;
if(niprivzeto) {
	if(gam==1) {
		std::cout << "Vnesi povprecno gibalno kolicino vpadnih fotonov [MeV/c]: " << std::endl;
		std::cin >> avrgP;
		std::cout << "Vnesi maksimalno gibalno kolicino vpadnih fotonov [MeV/c]: " << std::endl;
		std::cin >> maxP;
		std::cout << "Vnesi minimalno gibalno kolicino vpadnih fotonov [MeV/c]: " << std::endl;
		std::cin >> minP;
		std::cout << "Vnesi standardno deviacijo gibalne kolicine (sigma) vpadnih fotonov [MeV/c]: " << std::endl;
		std::cin >> sigmaP;
		}
	std::cout << "Nakljucno stevilo detektorjev? (1:Da, 2:Ne, 3:Vnesi svoje, 4:Iz datoteke 5: Vnesi max stevilo)" << std::endl;
	std::cin >> ran;
	if(ran==2 || ran==3) {
		std::cout << "Stevilo detektorjev (mora biti manjse ali enako st. pozicij - 32):" << std::endl;
		std::cin >> num_det1;
		}
	if ( ran==3) {	
		for(int i1=0; i1<num_det1; ++i1) {
			std::cout << "Vnesi stevilko pozicije:" << std::endl;
			std::cin >> own_conf[i1];				
			}
		nsims=1;	
		}
	if(ran==4) {
		std::cout << "Vnesi mesto in ime datoteke (npr. /home/.../file.dat):" << std::endl;
		std::cin >> filepath1;
		//filepath1="test1.dat";
		filepath = filepath1.c_str();
		std::cout << "odpiranje: "<< filepath << "..." <<std::endl;
		FILE *f42 = fopen(filepath, "rt");
		int vrstic2=0;
		while (EOF != (ch=getc(f42))){
        		if ('\n' == ch) ++vrstic2;
			}
		std::cout << vrstic2<< std::endl;
		FILE *f42 = fopen(filepath, "rt");
		int stolpcev3=0;
		int vrstic3=0;
		int stolpcev[vrstic2];
		while (EOF != (ch=getc(f42))){
			if('\t' ==ch) ++stolpcev3;
        		if ('\n' == ch) {
				stolpcev[vrstic3]=stolpcev3;				
				++vrstic3;
				std::cout << stolpcev3<< "\t";
				stolpcev3=0;
				}		
			}
		std::cout << "\n";
		//std::cout << stolpcev[0] << "\t"<<stolpcev[1] <<"\t" <<stolpcev[2] << std::endl;		
		//vrstic2= vrstic2-1;
		Int_t config[32][vrstic2];
		nsims=vrstic2-1;
		FILE *f42 = fopen(filepath, "rt");
		for(int u=0; u<vrstic2; ++u) {
			for(int u2=0; u2<=stolpcev[u]; ++u2) {	
				if(stolpcev[u]!=0) {
					if(u2==0) fscanf(f42,"%d", &config[u2][u]);
					if(u2!=0 && u2!=stolpcev[u]) fscanf(f42,"\t%d", &config[u2][u]);
					if(u2==stolpcev[u]) 	fscanf(f42,"\t%d\n", &config[u2][u]);
					}
				else fscanf(f42,"%d\n", &config[u2][u]);			
				}
			}
		fclose(f42);
		for(int u=0; u<vrstic2; ++u) {
			for(int u2=0; u2<=stolpcev[u]; ++u2) {
				printf("%d\t", config[u2][u]);
				}
			printf("\n");
			}			
		}
	if(ran==5) {
		std::cout << "Stevilo detektorjev (mora biti manjse ali enako st. pozicij - 32):" << std::endl;
		std::cin >> st_izbr_det;
		}	
	std::cout << "Vnesi stevilo meritev: " << std::endl;
	std::cin >> n;
	std::cout << "Vnesi stevilo fotonov (na meritev): " << std::endl;
	std::cin >> nfot;
	if(ran!=3 && ran!=4 && vir_spontan!=4) {
		std::cout << "Vnesi stevilo kombinacij: " << std::endl;
		std::cin >> nsims;	
		}	
	std::cout << "Nove nastavitve:"<<std::endl;
	if( gam==1) {	
		std::cout << "Povprecje:	" << avrgP << " MeV/c" <<std::endl;
		std::cout << "Max:		" << maxP << " MeV/c" <<std::endl;
		std::cout << "Min:		" << minP << " MeV/c" <<std::endl;
		std::cout << "St.dev:		" << sigmaP << " MeV/c" <<std::endl;
		}
	std::cout << "Meritev:		" << n <<std::endl;
	std::cout << "Fotonov:		" << nfot <<std::endl;
	std::cout << "Vseh fotonov:		" << n*nfot <<std::endl;
	if(vir_spontan!=4) std::cout << "Kombinacij:		" << nsims <<std::endl;
	if(vir_spontan==4) std::cout << "Stevilo tock: \t" << nsims <<std::endl;
	if(ran==1) std::cout << "Stevilo detektorjev je nakljucno." << std::endl;
	if(ran==2) std::cout << "Izbrano stevilo detektorjev:	" << num_det1 << std::endl;
	if(ran==3 || ran==4) std::cout << "Uporabnisko podana konfiguracija detektorjev." << std::endl;
	if(ran==5) std::cout << "Izbrano maksimalno stevilo detektorjev:	" << st_izbr_det << std::endl;
	}
/////////////////////////////////////////////////////////////////////////////////////////
//koliksno je stevilo pozicij, ki so na voljo;  oz. stevilo vrstic v coords.dat
FILE *g1 = fopen("coords.dat","rt");
Int_t vrstic=0;
while (EOF != (ch=getc(g1))) {
        if ('\n' == ch) ++vrstic;
	}
fclose(g1);
Int_t i=0;
Int_t sipm[vrstic];
Double_t ndetektorji[nsims], tocka[3]={0};
Double_t x1[vrstic],y1[vrstic], efficiency[nsims], efficiency_crta[Ncrta];
//parametri, ki jih zelimo videti v datafile.dat
Int_t seen[nsims];
Int_t seentot[nsims];
Int_t gentot[nsims];
Int_t gener[nsims];
Int_t seen_crta[Ncrta];
Int_t seentot_crta[Ncrta];
Int_t gentot_crta[Ncrta];
Int_t gener_crta[Ncrta];
char buffer1 [80];
char buffer2 [80];
strftime (buffer1,80,"datafile-%H-%M_%d-%m-%Y.dat",timeinfo);
strftime (buffer2,80,"datafile_best-%H-%M_%d-%m-%Y.dat",timeinfo);
std::ofstream datafile;
  datafile.open (buffer1);
std::ofstream datafile1;
  datafile1.open (buffer2);
//branje koordinat in indeksov detektorjev z datoteke
FILE *g1 = fopen("coords.dat","rt");
while (i<vrstic){
	fscanf(g1, "%d	%lf	%lf\n", &sipm[i], &x1[i], &y1[i]);
	printf("%d	%f	%f\n", sipm[i], x1[i], y1[i]);
	++i;
	}
fclose(g1);
//random number generator TRandom3()
TRandom *random = new TRandom3();
random->TRandom3::SetSeed(0);
//////////////////////////////////////////////////////////////////////////////////
//nekaj parametrov in konstant
Int_t random_num_det;
Int_t izbran[vrstic];
Int_t detektorji=vrstic;
Int_t st_det=vrstic;
Int_t j=0;
Int_t j2=0;
Int_t izbrandet; 
Double_t detektor_dx=0.3, detektor_dy=0.3, detektor_dz=0.1;
Double_t Air_RefrIndex = 1.0003;  
const Double_t aluminium_diffus  = 0.01;//probi pr razlicnih
const Double_t AluminiumSupplAbs = 0.1;
Double_t nPhotMeV = 8200;
Double_t BGO_RefrIndex = 2.15;
TVector3 zero_vector(0.0,0.0,0.0);
Int_t mediumindex=1;
TVector3 dir(0.0,0.0,1.0);
TVector3 dirfce(0.0,0.0,1.0);
const char* pot = "/TOP_1/SOURCE_1";
const char *comTL = "Bi4Ge3O12 with Al housing";
gCleanOut->fMaxInfo = 100000;
TLitPhys::Get()->SetLate(2000000);
gCleanOut->fMaxKill = 100000000;
TLitPhys::Get()->SetAnomal(10000000); 
TLitPhys::Get()->SetBiggestStep(10);
TLitPhoton::fgNPointsMax = 100000;
//Load some stuff
gROOT->ProcessLine(".L PhotoEl_Air.C"); //v $ROOTDEV/macros
gROOT->ProcessLine(".L PhotoEl_BGO.C");  // v $ROOTDEV/macros (mora bit dodan na seznam v SplineFitDB.rdb)
gROOT->ProcessLine(".L PhotoEl_Aluminium.C"); // v $ROOTDEV/macros
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7
//zacnemo zanko
for(Int_t sims=0; sims<=nsims;++sims) {
	TStopwatch t;
	t.Start();
	random->TRandom3::SetSeed(0);
//TGeoManager
	std::stringstream buffer;
	buffer << "setup" << sims<< std::endl;
	std::string setup1 = buffer.str();
	const char* setup = setup1.c_str();
	std::cout << setup << std::endl;
	TGeoManager *geom = new TGeoManager(setup, "Geometrija");
/////////////////////////////////////////////////////////////////////////
//MATERIALI
//totalna absorbcija
	TGeoMaterial *matTotAbs= new TGeoMaterial("TotAbsorb",0.0,0.0,0.0);
	TLitMedium *TotAbs = new TLitMedium("TotAbs",mediumindex++,matTotAbs,-1.0);
	TotAbs->SetAsWrapping(0.0,0.0,1.0,1.0,1.0);
	TotAbs->IsIsotropic(1.0);
//Vacuum
	TGeoMaterial *matVacuum = new TGeoMaterial("Vacuum", 0,0,0);
	TGeoMedium *Vacuum = new TGeoMedium("Vacuum",mediumindex++, matVacuum);
//zrak - okoli detektorja  
	TGeoElementTable *table = gGeoManager->GetElementTable();
	TGeoElement *N  = table->FindElement("NITROGEN");
	TGeoElement *O  = table->FindElement("OXYGEN");
	TGeoMixture *Air_mix = new TGeoMixture("Air_mix",2,0.00129);
	Air_mix->AddElement(N,0.7);
	Air_mix->AddElement(O,0.3);
	TLitMedium *Air = new TLitMedium("Air",mediumindex++,Air_mix,kFALSE,1.0,10000.0);
	Air->IsIsotropic(Air_RefrIndex);
	TSplineFit *fitPEAir = PhotoEl_Air();
	Air->SetXSectnPE(fitPEAir);
//aluminij za ohisje
	TGeoElement *Al = table->FindElement("ALUMINIUM");
	TGeoMaterial *matAl = new TGeoMaterial("Aluminij", Al,2.6995);
	TLitMedium *Aluminij = new TLitMedium("Aluminij",mediumindex++, matAl, 1.0);
	Aluminij->SetAsWrapping(aluminium_diffus,"RIndexRev_Aluminium","IIndexRev_Aluminium",1.0,AluminiumSupplAbs);
	Aluminij->IsIsotropic(1.0);
	TSplineFit *fitPEAlu = PhotoEl_Aluminium();
	Aluminij->SetXSectnPE(fitPEAlu);
//BGO (https://www.crystals.saint-gobain.com/sites/imdf.crystals.com/files/documents/bgo-material-data-sheet_69763.pdf)
	TGeoElement *Bi = table->FindElement("BISMUTH");
	TGeoElement *Ge = table->FindElement("GERMANIUM");
//TGeoElement *O  = table->FindElement("OXYGEN"); ze definiran
	TGeoMixture *BGO_mix = new TGeoMixture("BGO_mix",3,7.13);
	BGO_mix->AddElement(Bi,4);
	BGO_mix->AddElement(Ge,3);
	BGO_mix->AddElement(O,12);
	BGO_mix->SetRadLen(0.8,19);
	BGO_mix->SetFillColor(kRed);
	TLitMedium *BGO = new TLitMedium("BGO", mediumindex++, BGO_mix, kFALSE,1.0, 100.0);
	BGO->IsIsotropic(BGO_RefrIndex);
	TLitSpectrum *spektr = new TLitSpectrum("Spektr_BGO", "Emisijski spekter | BGO");
	spektr->AddOneComponent(480.0, 60.0, 1.0 , 60.0,-1.0, 0.1 ,300.0,-1.0,0.9);
	spektr->Normalize();
	BGO->SetPhotMev(nPhotMeV);
	BGO->SetLitSpectrum(spektr);
	BGO->SetXSectnPE("PhotoEl_BGO");
//Silicij
	TGeoElement *Si = table->FindElement("SILICON");
	TGeoMaterial *matSi = new TGeoMaterial("Si", Si, 2.33);
	matSi->SetFillColor(kGreen);
	TLitMedium *Silicij = new TLitMedium("Si", mediumindex++, matSi,kTRUE,1.0,"AbsorptionLength_Silicium");
	Silicij->IsIsotropic("RefrIndex_Silicium");
////////////////////////////////////////////////////////////////////////////////
//GEOMETRIJA
//Transformacije - translacije
	TGeoTranslation *t1 = new TGeoTranslation("t1",-4.907477288,0, 2.525);
	TGeoTranslation *t3 = new TGeoTranslation("t3",-4.907477288,0, 2.95);
	TGeoTranslation *t4 = new TGeoTranslation("t4",0.0,0.0,5.05);
	TGeoTranslation *t5 = new TGeoTranslation("t5",0.0,0.0,0.15);
	TGeoTranslation *t6 = new TGeoTranslation("t6",0.0,0.0,-5);
	TGeoTranslation *t7 = new TGeoTranslation("t7",-4.907477288,0.0, 0.10);
	TGeoTranslation *t8 = new TGeoTranslation("t8",0.0,0.0,2.6);
	TGeoRotation *r1 = new TGeoRotation("r1", 0,180, 0);
//razglasitev rotacij in translacij
	r1->RegisterYourself();
	t1->RegisterYourself();
	t3->RegisterYourself();
	t4->RegisterYourself();
	t5->RegisterYourself();
	t6->RegisterYourself();
	t7->RegisterYourself();
	t8->RegisterYourself();
//svet
	TGeoVolume *top = gGeoManager->MakeBox("TOP", Air, 20.,20.,20.);
	geom->SetTopVolume(top);
//Pgon - 6kotniki
	TGeoVolume *vol1 = gGeoManager->MakePgon("PGON", Aluminij,0,360, 6,2);
	TGeoPgon *pgon = (TGeoPgon*)(vol1->GetShape());
	pgon->DefineSection(0,0.0,0.0,4.249);
	pgon->DefineSection(1,5.9,0,4.249);
	TGeoVolume *vol3 = gGeoManager->MakePgon("PGON3", Aluminij,0,360, 6,2);
	TGeoPgon *pgon3 = (TGeoPgon*)(vol3->GetShape());
	pgon3->DefineSection(0,0,0,4.1);
	pgon3->DefineSection(1,0.2,0,4.1);
//Tube
	TGeoVolume *vol4 = gGeoManager->MakeTubs("TUBS", Air, 0,2.5 ,2.9500001, -60.0001,60.0001);
	TGeoVolume *vol5 = gGeoManager->MakeTubs("TUBS2", Air, 0,2.65 ,2.5250001, -60.0001,60.0001);
	TGeoVolume *vol7 = gGeoManager->MakeTubs("TUBS4", Air, 0,2.65 ,0.10001, -60.0001,60.0001);
	TGeoVolume *volCev= gGeoManager->MakeTubs("TUBS5", Aluminij, 2.5,2.65 ,2.95, -60.0001,60.0001);
//BGO
	TGeoVolume *volBGO1 = gGeoManager->MakePgon("volBGO1", BGO,0,360, 6,2);
	TGeoPgon *pgonBGO = (TGeoPgon*)(volBGO1->GetShape());
	pgonBGO->DefineSection(0,0,0,4.1);
	pgonBGO->DefineSection(1,2.45,0,4.1);
//vir sevanja
	if(gam==1) {	
		if(vir_gam==1) {
			TGeoVolume *source = geom->MakeEltu("SOURCE",Air,0.1,0.1,0.1);
			}	
		else {
			if(vir_gam==2 || vir_gam==3) {
				TGeoTranslation *tS6 = new TGeoTranslation("tS6",0.0,0.0,-5);
				tS6->RegisterYourself();
				TGeoCompositeShape *vol_compSource1 = new TGeoCompositeShape("vol_compSource1", "PGON3-TUBS4:t7");
				TGeoVolume *source1 =  new TGeoVolume("SOURCE1", vol_compSource1, Air);
				}
			if(vir_gam==2) {
				TGeoVolume *source2 = geom->MakeBox("SOURCE2", Air, 4.1,2.45,0.1);
				TGeoVolume *source3 = geom->MakeBox("SOURCE3", Air, 2.95,2.45,0.1);	
//translacije in rotacije ploskev

				TGeoRotation *rS1 = new TGeoRotation("rS1", 0,90, 0);
				TGeoCombiTrans *cS1 = new TGeoCombiTrans("cS1", 1.25,10.0,2.55, rS1);
				cS1->RegisterYourself();
				TGeoRotation *rS2 = new TGeoRotation("rS2", 270,90, 0);
				TGeoCombiTrans *cS2 = new TGeoCombiTrans("cS2", 10.0,0.0,2.55, rS2);
				cS2->RegisterYourself();
				TGeoRotation *rS3 = new TGeoRotation("rS3", 180,90,0);
				TGeoCombiTrans *cS3 = new TGeoCombiTrans("cS3", 1.25,-10.0,2.55, rS3);
				cS3->RegisterYourself();
				TGeoRotation *rS4 = new TGeoRotation("rS4", 90,90, 0);
				TGeoCombiTrans *cS4 = new TGeoCombiTrans("cS4", -10.0,0.0,2.55, rS4);
				cS4->RegisterYourself();
				}
			}
		}
//sestavljene oblike
	TGeoCompositeShape *vol_comp = new TGeoCompositeShape("vol_comp", "(PGON)-(TUBS:t3)");
	TGeoVolume *volAL = new TGeoVolume("VOLAL", vol_comp, Aluminij);
	TGeoCompositeShape *vol_compBGO1 = new TGeoCompositeShape("vol_compBGO1", "(volBGO1)-TUBS2:t1");
	TGeoVolume *volBGO1 = new TGeoVolume("VOLBGO_1", vol_compBGO1, BGO);
	TGeoCompositeShape *vol_compBGO = new TGeoCompositeShape("vol_compBGO", "(vol_compBGO1) + (vol_compBGO1:r1)");//ker ima sicer problem s spodnjo mejo 6kotnika
	TGeoVolume *volBGO = new TGeoVolume("VOLBGO", vol_compBGO, BGO);
	TLitVolume *BGO_lit = new TLitVolume(volBGO);
	TLitVolume *top_lit = new TLitVolume(top);
	TLitVolume *AL_lit = new TLitVolume(volAL);
//////////////////////////////////////////////////////////////////////////////////////
//DETEKTOR-JI
/////////////////////////////////////////////////////////////////////////////////////
//Oblika detektorja - skatlast:
	TGeoVolume *volDET = geom->MakeBox("VOLDET",Silicij,detektor_dx,detektor_dy,detektor_dz);
	TLitVolume *detektor = new TLitVolume(volDET);
	//detektor->SetAPD("GainProfile_CMSAPD",1); //za primer: CMSAPD
	detektor->SetDetector(kTRUE,"",-1);
//plast Total Absorption okoli detektorjev
	TGeoCompositeShape *vol_compTOT = new TGeoCompositeShape("vol_compTOT", "PGON3-TUBS4:t7");
	TGeoVolume *volTOT =  new TGeoVolume("VOLTOT", vol_compTOT, TotAbs);
	j=0;
	j2=0;
//nakljucno izbiranje stevila detektorjev
	if(ran==1 || ran==2) {
		if (ran==1) random_num_det= random->TRandom::Integer(st_det-1)+1;
		if (ran==2) random_num_det= num_det1;
		if (ran==5) random_num_det= random->TRandom::Integer(st_izbr_det-1)+1;
		std::cout << ran << "\t" << random_num_det << "\t" << num_det1 << std::endl;
		if(sims==0){
			for(int j=0; j<st_det;++j) {
				TGeoTranslation *tdet = new TGeoTranslation("tdet",x1[j],y1[j],detektor_dz);
				tdet->RegisterYourself();
				volTOT->AddNode(volDET,sipm[j],tdet);
				}
			}
		else {
			std::cout << "Stevilo detektorjev:	" <<random_num_det<< std::endl;
	//nakljucno izbiranje detektorjev
			while( j2<random_num_det) {
				Int_t  compare=0;
				izbran[j2] = random->TRandom::Integer(st_det);
				izbrandet = izbran[j2];
				for(Int_t j3=0; j3<j2;++j3) {
					if(izbrandet==izbran[j3]) ++compare;
					}
				if(compare==0) {	
					TGeoTranslation *tdet = new TGeoTranslation("tdet",x1[izbrandet],y1[izbrandet],detektor_dz);
					tdet->RegisterYourself();
					volTOT->AddNode(volDET,sipm[izbrandet],tdet);
					std::cout <<"sipm:  " <<sipm[izbrandet]<< std::endl;
					}
				else j2=j2-1;
				++j2;
				}
			detektorji=random_num_det;
			}
		ndetektorji[sims]=detektorji;
		}
	if(ran==3) {
		for(int k1=0; k1<num_det1; ++k1) {
			izbrandet=own_conf[k1];
			izbran[k1]=own_conf[k1];
			TGeoTranslation *tdet = new TGeoTranslation("tdet",x1[izbrandet],y1[izbrandet],detektor_dz);
			tdet->RegisterYourself();
			volTOT->AddNode(volDET,sipm[izbrandet],tdet);
			std::cout <<"sipm:  " <<sipm[izbrandet]<< std::endl;
			}
		ndetektorji[sims]=num_det1;
		}
	if(ran==4) {
		for(int k1=0; k1<=stolpcev[sims]; ++k1) {
			izbrandet=config[k1][sims] -1;
			//izbran[k1]=config[k1][sims] -1;
			TGeoTranslation *tdet = new TGeoTranslation("tdet",x1[izbrandet],y1[izbrandet],detektor_dz);
			tdet->RegisterYourself();
			volTOT->AddNode(volDET,sipm[izbrandet],tdet);
			std::cout <<"sipm:  " <<sipm[izbrandet]<< std::endl;
			}
		ndetektorji[sims]=stolpcev[sims] +1;
		}
////////////////////////////////////////////////////////////////////////////////////
//RISANJE GEOMETRIJE
	TLit::Get()->BookCanvas();
	gGeoManager->SetTopVisible(1);
	top->SetVisContainers();
//TwoPad Nastavitve
	gTwoPad->SetAllGrey();
	gTwoPad->CommentTL(comTL);
	top->SetVisContainers();
	top->SetLineColor(1);
	top->SetLineWidth(1);
//parametri komponent
	volAL->SetLineWidth(1);
	volAL->SetLineColor(kGray);
	volAL->SetVisibility(kTRUE);
	volBGO->SetLineWidth(1);
	volBGO->SetLineColor(kViolet);
	volBGO->SetVisibility(kTRUE);
	volDET->SetVisibility(kTRUE);
	volDET->SetLineColor(kGreen);
	volDET->SetLineWidth(1);
	volTOT->SetVisibility(kTRUE);
	volTOT->SetLineWidth(1);
	volTOT->SetLineColor(kBlue);
	volCev->SetLineWidth(1);
	volCev->SetLineColor(kGray);
	volCev->SetVisibility(kTRUE);
//ADDNODE
	if(gam==1 && vir_gam==1) {
		source->SetLineWidth(1);
		source->SetLineColor(kYellow);
		source->SetVisibility(kTRUE);
		top->AddNode(source,1,t6);
		}
	if(gam==1 && vir_gam==2){
		source1->SetLineWidth(1);
		source1->SetLineColor(kYellow);
		source1->SetVisibility(kTRUE);
		source2->SetLineWidth(1);
		source2->SetLineColor(kYellow);
		source2->SetVisibility(kTRUE);
		source3->SetLineWidth(1);
		source3->SetLineColor(kYellow);
		source3->SetVisibility(kTRUE);
		top->AddNode(source1,1, tS6);
		top->AddNode(source3,1, cS1);
		top->AddNode(source2,2, cS2);
		top->AddNode(source3,3, cS3);
		top->AddNode(source2,4, cS4);
		}
	if(gam==1 && vir_gam==3) {
		source1->SetLineWidth(1);
		source1->SetLineColor(kYellow);
		source1->SetVisibility(kTRUE);
		top->AddNode(source1,1, tS6);
		}
	volAL->AddNode(volCev,1,t3);
	volAL->AddNode(volBGO,1,t8);
	volAL->AddNode(volTOT,1, t4);
	top->AddNode(volAL,1);
//geom nastavitve
	geom->CloseGeometry();
	geom->CheckOverlaps(0.01);
	geom->SetVisLevel(4);
	geom->SetVisOption(0);
//gGeoManager nastavitve
	gGeoManager->SetTopVisible(0);
	gGeoManager->SetVisLevel(4);
	//gGeoManager->Edit();
//narisemo
	top->Draw();
//////////////////////////////////////////////////////////////////////////////////
	if(gam==1) {
//generacija gama fotonov
		if(vir_gam==1) {
			TLitGamma *Gamma = new TLitGamma("Gammas","Gamma photon",pot,avrgP,kFALSE,kFALSE, gaussian,minP,maxP,sigmaP);
			Gamma->SetEmission(flat,20.0,dir,"",kFALSE,zero_vector,kTRUE,dirfce);
			//Gamma-> WhichToDraw(10000000);
			if( n>=1) {
				for(int k100=1+sims*n; k100<=n+sims*n;++k100) {
					Gamma->Gen(k100,nfot,k100,kTRUE, kFALSE);
					Gamma->IsToDraw(100000);
					}
				}
			}
		if(vir_gam==2) {
			TLitGamma *Gamma1 = new TLitGamma("Gamma1","Gamma photon","/TOP_1/SOURCE1_1",avrgP,kFALSE,kFALSE, gaussian,minP,maxP,sigmaP);
			Gamma1->SetEmission(flat,0,dir,"",kFALSE,zero_vector,kTRUE,dirfce);
			TLitGamma *Gamma2_1 = new TLitGamma("Gamma2_1","Gamma photon","/TOP_1/SOURCE3_1",avrgP,kFALSE,kFALSE, gaussian,minP,maxP,sigmaP);
			Gamma2_1->SetEmission(flat,0,dir,"",kFALSE,zero_vector,kTRUE,dirfce);
			TLitGamma *Gamma2_2 = new TLitGamma("Gamma2_2","Gamma photon","/TOP_1/SOURCE2_2",avrgP,kFALSE,kFALSE, gaussian,minP,maxP,sigmaP);
			Gamma2_2->SetEmission(flat,0,dir,"",kFALSE,zero_vector,kTRUE,dirfce);
			TLitGamma *Gamma2_3 = new TLitGamma("Gamma2_3","Gamma photon","/TOP_1/SOURCE3_3",avrgP,kFALSE,kFALSE, gaussian,minP,maxP,sigmaP);
			Gamma2_3->SetEmission(flat,0,dir,"",kFALSE,zero_vector,kTRUE,dirfce);
			TLitGamma *Gamma2_4 = new TLitGamma("Gamma2_4","Gamma photon","/TOP_1/SOURCE2_4",avrgP,kFALSE,kFALSE, gaussian,minP,maxP,sigmaP);
			Gamma2_4->SetEmission(flat,0,dir,"",kFALSE,zero_vector,kTRUE,dirfce);	
			if( n>=1) {
				Int_t g_ran;
				for(int k101=1+sims*100000; k101<=n+sims*100000;++k101) {
					g_ran= random->TRandom3::Integer(5);
					if(g_ran==0) Gamma1->Gen(k101,nfot,k101);
					if(g_ran==1) Gamma2_1->Gen(k101,nfot,k101);
					if(g_ran==2) Gamma2_2->Gen(k101,nfot,k101);
					if(g_ran==3) Gamma2_3->Gen(k101,nfot,k101);
					if(g_ran==4) Gamma2_4->Gen(k101,nfot,k101);
					}
				}
			}	
		if(vir_gam==3) {
			TLitGamma *Gamma1 = new TLitGamma("Gamma1","Gamma photon","/TOP_1/SOURCE1_1",avrgP,kFALSE,kFALSE, gaussian,minP,maxP,sigmaP);
			Gamma1->SetEmission(flat,0,dir,"",kFALSE,zero_vector,kTRUE,dirfce);
			for(int k102=1+sims*n*nfot; k102<=n+sims*n*nfot;++k102) {
				Gamma1->Gen(k102,nfot,k102);
				}
			}
		}
	else {
//generacija fotonov
		TLitSpontan *spontan = new TLitSpontan("Gammas","Foton v BGO", "/TOP_1/VOLAL_1/VOLBGO_1",kFALSE,kFALSE);
		if(vir_spontan==1) spontan->SetEmission();
		if(vir_spontan==2) {
			spontan->SetEmission(on4pi,180.0,dir,"",kTRUE,source_spontan_vector,kFALSE,zero_vector);
			Double_t tocka1[3]={Xsp,Ysp,Zsp};
			vsebuje= volBGO->TGeoVolume::Contains(tocka1);
			if(vsebuje==kFALSE) {
				std::cout << "Napaka: Tocke ni v volumnu."<<std::endl;
			//	break;
				}
			}
		spontan->TrackToDraw(2000000000);
		if( n>=1 && vir_spontan<3) {
			for(int k103=1+sims*n*nfot; k103<=n+sims*n*nfot;++k103) {
				spontan->Gen(k103,nfot,k103);
				spontan->GetRecordedTracks();
				}
			}
		if(vir_spontan==3) {
			for (int N42=0; N42<Ncrta;++N42) { //za manj pisanja sem za ploskev vzel iste spremenljivke kot pri crti
				TStopwatch t_ploskev;
				t_ploskev.Start();
				Xsp=random->TRandom3::Uniform(-4.74,4.74);
				Ysp=random->TRandom3::Uniform(-4.74,4.74);
				Double_t tocka[3]={Xsp,Ysp,Zsp};
				vsebuje= volBGO->TGeoVolume::Contains(tocka);
				TVector3 source_spontan_vector1(Xsp,Ysp,Zsp);
				//std::cout << "TLitSpontan - Tocka na koordinatah ("<< Xsp<<","<<Ysp<<","<<Zsp<<")." <<std::endl;

				//std::cout << vsebuje << std::endl;
				if(vsebuje) {
					TVector3 source_spontan_vector1(Xsp,Ysp,Zsp);
					std::cout << "TLitSpontan - Tocka #"<< N42 <<" na koordinatah ("<< Xsp<<","<<Ysp<<","<<Zsp<<")." <<std::endl;

					for(int k103=1+sims*n*nfot; k103<=n+sims*n*nfot;++k103) {
						spontan->SetEmission(on4pi,180.0,dir,"",kTRUE,source_spontan_vector1,kFALSE,zero_vector);
						spontan->Gen(k103,nfot,k103);
						spontan->GetRecordedTracks();
						}
					gLitGp->SetTitle("n (st.meritve)");
					gLitGp->Summary();
					gTwoPad->ChangePad();
					gLitGs->DoStat();
					TLit::Get()->CloseFiles();
					TFile *f = new TFile(listing2,"READ");
					seentot_crta[N42] = GlobStat->fNpSeen;
					if(N42==0) {
						if(sims==0) seen_crta[N42]=seentot_crta[N42];
						else seen_crta[N42]=seentot_crta[N42]-seentot[sims-1];
						}
					else seen_crta[N42]=seentot_crta[N42] - seentot_crta[N42-1];
					gentot_crta[N42]= GlobStat->fNpGener;
					if(N42==0) gener_crta[N42]=gentot_crta[N42];
					else gener_crta[N42]=gentot_crta[N42] - gentot_crta[N42-1];
					efficiency_crta[N42] = (double) seen_crta[N42] / (double) gener_crta[N42];
					datafile3 << efficiency_crta[N42] <<"\t"<< Xsp <<"\t"<< Ysp<< std::endl;
					gLitGp->ClearHistos();
					spektr->ClearGraphs();
					f->Close();
					}
				else {
					N42=N42-1;
					std::cout << "Tocke ni v volumnu: Poskusimo znova."<<std::endl;
					}
				random->TRandom3::SetSeed(0);
				t_ploskev.Stop();
				t_ploskev.Print();				
				}
			}
		if(vir_spontan==4) {
			datafile2 << "#Kombinacija st:\t" <<sims<<std::endl;
			datafile2 << "#efficiency\t x[cm]"<<std::endl;
			for(int N42=0; N42<Ncrta; ++N42) {
				TStopwatch t_crta;
				t_crta.Start();
				std::cout << "TLitSpontan - Tocka na koordinatah ("<< Xcrta<<","<<Ycrta<<","<<Zcrta<<")." <<std::endl;
				for(int k103=1+sims*n*nfot*N42; k103<=n+sims*n*nfot*N42;++k103) {
					spontan->SetEmission(on4pi,180.0,dir,"",kTRUE,source_spontan_vector2,kFALSE,zero_vector);
					spontan->Gen(k103,nfot,k103);
					spontan->GetRecordedTracks();
					}
				gLitGp->SetTitle("n (st.meritve)");
				gLitGp->Summary();
				gTwoPad->ChangePad();
				gLitGs->DoStat();
				TLit::Get()->CloseFiles();
				TFile *f = new TFile(listing2,"READ");
				seentot_crta[N42] = GlobStat->fNpSeen;
				if(N42==0) {
					if(sims==0) seen_crta[N42]=seentot_crta[N42];
					else seen_crta[N42]=seentot_crta[N42]-seentot[sims-1];
					}
				else seen_crta[N42]=seentot_crta[N42] - seentot_crta[N42-1];
				gentot_crta[N42]= GlobStat->fNpGener;
				if(N42==0) gener_crta[N42]=gentot_crta[N42];
				else gener_crta[N42]=gentot_crta[N42] - gentot_crta[N42-1];
				efficiency_crta[N42] = (double) seen_crta[N42] / (double) gener_crta[N42];
				datafile2 << efficiency_crta[N42] <<"\t"<< Xcrta << std::endl;
				gLitGp->ClearHistos();
				spektr->ClearGraphs();
				f->Close();
				t_crta.Stop();
				t_crta.Print();
				Xcrta=Xcrta+dXcrta;
				TVector3 source_spontan_vector2(Xcrta,Ycrta,Zcrta);				
				}
			}
		}
	gLitGp->SetTitle("n (st.meritve)");
	gLitGp->Summary();
	gTwoPad->ChangePad();
	gLitGs->DoStat();
	TLit::Get()->CloseFiles();
	TFile *f = new TFile(listing2,"READ");
	seentot[sims] = GlobStat->fNpSeen;
	if(sims==0) seen[sims]=seentot[sims];
	else seen[sims]=seentot[sims] - seentot[sims-1];
	gentot[sims]= GlobStat->fNpGener;
	if(sims==0) gener[sims]=gentot[sims];
	else gener[sims]=gentot[sims] - gentot[sims-1];
	efficiency[sims] = (double) seen[sims] / (double) gener[sims];
	if(sims==0) {
	//header
		datafile << "#Nastavitve:"<<std::endl;
		if (gam==1) {
			datafile << "#Povprecje:	" << avrgP << " MeV/c" <<std::endl;
			datafile << "#Max:		" << maxP << " MeV/c" <<std::endl;
			datafile << "#Min:		" << minP << " MeV/c" <<std::endl;
			datafile << "#St.dev:		" << sigmaP << " MeV/c" <<std::endl;
			}
		datafile << "#Meritev:		" << n <<std::endl;
		datafile << "#Fotonov:		" << nfot <<std::endl;
		datafile << "#Vseh fotonov:		" << n*nfot <<std::endl;
		if(vir_spontan!=4) datafile << "#Kombinacij:\t" << nsims << std::endl;
		if(vir_spontan==4) datafile << "#Stevilo tock:\t" << nsims << std::endl;
		if ( gam==1 & vir_gam==1) datafile << "#Vir gamma zarkov na koordinatah (0,0,-5)." << std::endl;
		if ( gam==1 & vir_gam==2) datafile << "#Vir gamma zarkov so ploskve okoli detektorja." << std::endl;
		if ( gam==1 & vir_gam==3) datafile << "#Vir gamma zarkov je ploskev pod detektorjem." << std::endl;
		if (gam==2 & vir_spontan==1) datafile << "#TLitSpontan - cela prostornina kristala." <<std::endl;
		if (gam==2 & vir_spontan==2) datafile << "#TLitSpontan - Tocka na koordinatah ("<< Xsp<<","<<Ysp<<","<<Zsp<<")." <<std::endl;
		if (gam==2 & vir_spontan==3) datafile << "#TLitSpontan - Nakljucno izbrana tocka s Z = "<< Zsp <<std::endl;
		if (gam==2 & vir_spontan==4){			
			datafile << "#Visina crte :\t" << Zcrta << std::endl;
			datafile << "#Y crte :\tY = " << Ycrta << std::endl;
			datafile << "#Zacetek crte :\tX = " << Xstart << std::endl;
			datafile << "#Konec crte :\tX = "<< Xkonec << std::endl;
			datafile << "#Stevilo tock :\t"<< Ncrta << std::endl;
			}
		if(ran==1) datafile << "#Stevilo detektorjev je nakljucno." << std::endl;
		if(ran==2) datafile<< "#Izbrano stevilo detektorjev:	" << num_det1 << std::endl;
		if(ran==3 || ran==4) datafile << "#Uporabnisko podana konfiguracija detektorjev." << std::endl;
		if(ran==5) datafile << "Izbrano maksimalno stevilo detektorjev:	" << st_izbr_det << std::endl;
		datafile << "#n \t counts \t num_of_detec \t avrg.counts/det\t efficiency (seen/gen) \t||"<<std::endl;
		datafile << "#controlna: " << sims<< "\t"  << seen[sims]<< "\t" << ndetektorji[sims] <<"\t" << seen[sims]/ndetektorji[sims]<< "\t" << efficiency[sims] << std::endl;
		//datafile1 << sims << "\t" << seen[sims] << "\t" << efficiency[sims]<< std::endl;
		}

	else {
		datafile << sims << "\t" <<seen[sims] << " \t " << ndetektorji[sims]<<" \t " <<  seen[sims]/ndetektorji[sims]  << "\t" << efficiency[sims]  <<" \t || \t";
		//datafile1 << sims << "\t" << seen[sims] << "\t" << efficiency[sims] << std::endl;
	
		for(int ii=0; ii< st_izbr_det; ++ii) {
			if (ii<ndetektorji[sims]) datafile <<"\t" <<sipm[izbran[ii]];
			else datafile <<"\t" << "/";
			}
	
		datafile << std::endl;
		}
	if(sims<nsims) {
		/*
		volDET->TGeoVolume::ClearNodes();
		volAL->TGeoVolume::ClearNodes();
		top->TGeoVolume::ClearNodes();
		vol1->ClearShape();
		vol3->ClearShape();
		vol4->ClearShape();
		vol5->ClearShape();
		vol7->ClearShape();
		volBGO1->ClearShape();
		volBGO->ClearShape();
		volDET->ClearShape();
		volAL->ClearShape();
		top->ClearShape();
		*/
		gGeoManager = 0;
		gLitGp->ClearHistos();
		spektr->ClearGraphs();
		spektr->TLitSpectrum::Clear();
		
		TSeqCollection* canvases = gROOT->GetListOfCanvases();
		TIter next(gROOT->GetListOfCanvases());
		while(c = (TCanvas*)next()) {
			delete c;
			}
		}
	f->Close();
	buffer.str(std::string());
	t.Stop();
	t.Print(); 
	}
std::cout << "n" << '\t' << "seen"  <<"\t"<< "N det." << "\t" << "eff." << std::endl;
for(Int_t z=0; z<=nsims; ++z) {
	std::cout << z << '\t' << seen[z] <<"\t"<< ndetektorji[z] << "\t" << efficiency[z] << std::endl;
	}
Double_t najbol;
Int_t najbolcifra;
for(int z1=1; z1<=nsims;++z1) {
	if(z1==1) {
		najbol=efficiency[z1];
		najbolcifra=z1;
		}
	else {
		if(efficiency[z1] > najbol) { 
			najbol=efficiency[z1];
			najbolcifra=z1;
			}
		}
	}
std::cout << "\n" <<std::endl;
Double_t najbolNdet[33]={0};
Double_t najbolseen[33]={0};
Double_t najbolgener[33]={0};
Double_t najboleff[33]={0};
Double_t z42[33];
Double_t eff;
datafile1 << "#st.det\tst.run\teff\tgener\tseen\t "<< std::endl;
for(int z=1; z<=32;++z) {
	for(int s=0; s<=nsims; ++s) {	
		if(ndetektorji[s]==z) {		
		eff= (double) seen[s] / (double) gener[s];
		if(eff > najboleff[z]) {
				najbolNdet[z]=s;
				najbolgener[z]=gener[s];
				najbolseen[z]=seen[s];
				najboleff[z]= eff;
				}		
			}	
		}
	z42[z]=z;
	std::cout << z << "\t"  << najbolNdet[z] << "\t" << najboleff[z] << "\t" <<najbolgener[z] <<"\t"<< najbolseen[z]<< std::endl;
	datafile1 << z << "\t"  << najbolNdet[z] << "\t" << najboleff[z] <<"\t"<< najbolgener[z] <<"\t"<< najbolseen[z]<< std::endl;
	}
datafile << "#Najboljsa konfiguracija:\t" << najbolcifra << "\t"<< "Ucinkovitost:\t" << najbol << std::endl; 
std::cout<< "Najboljsa konfiguracija:\t" << najbolcifra << "\t"<< "Ucinkovitost:\t" << najbol << std::endl; 
std::cout<< "Kontrolna:\t" << "..." << "\t"<< "Ucinkovitost:\t" << efficiency[0] << std::endl; 
datafile.close();
datafile1.close();
datafile2.close();
TLit::Get()->CloseFiles();
puts (buffer1);
puts (buffer2);
TGraph *gr1 = new TGraph (33,z42, najboleff);
TCanvas *c42 = new TCanvas ("c42",buffer2,200,10,800,400);
c42->cd(4);
gr1->SetTitle("seen/gen");
gr1->SetMarkerStyle(7);
gr1->SetMarkerColor(4);
gr1->Draw("AP");
TGraph *gr2 = new TGraph (33,z42, najbolseen);
TCanvas *c43 = new TCanvas ("c43",buffer2,200,10,800,600);
c43->cd(5);
gr2->SetTitle("seen");
gr2->SetMarkerStyle(7);
gr2->SetMarkerColor(3);
gr2->Draw("AP");
TGraph *gr3 = new TGraph (nsims,ndetektorji, efficiency);
TCanvas *c44 = new TCanvas ("c44",buffer3,200,10,800,600);
c44->cd(6);
gr3->SetTitle("seen/gen (all runs)");
gr3->SetMarkerStyle(6);
gr3->SetMarkerColor(2);
gr3->Draw("AP"); 
}
