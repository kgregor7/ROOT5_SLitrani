/********************************************************************
* SLitraniDict.h
* CAUTION: DON'T CHANGE THIS FILE. THIS FILE IS AUTOMATICALLY GENERATED
*          FROM HEADER FILES LISTED IN G__setup_cpp_environmentXXX().
*          CHANGE THOSE HEADER FILES AND REGENERATE THIS FILE.
********************************************************************/
#ifdef __CINT__
#error SLitraniDict.h/C is only for compilation. Abort cint.
#endif
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define G__ANSIHEADER
#define G__DICTIONARY
#define G__PRIVATE_GVALUE
#include "G__ci.h"
#include "FastAllocString.h"
extern "C" {
extern void G__cpp_setup_tagtableSLitraniDict();
extern void G__cpp_setup_inheritanceSLitraniDict();
extern void G__cpp_setup_typetableSLitraniDict();
extern void G__cpp_setup_memvarSLitraniDict();
extern void G__cpp_setup_globalSLitraniDict();
extern void G__cpp_setup_memfuncSLitraniDict();
extern void G__cpp_setup_funcSLitraniDict();
extern void G__set_cpp_environmentSLitraniDict();
}


#include "TObject.h"
#include "TMemberInspector.h"
#include "TLitPol3.h"
#include "TLitPol4.h"
#include "TLitEqIndex.h"
#include "TLitWave.h"
#include "TLitHistParams.h"
#include "TLitPhys.h"
#include "TLitTrap.h"
#include "TLitSpectrumCp.h"
#include "TLitSpectrum.h"
#include "TLitDetector.h"
#include "TLitSellmeier.h"
#include "TLitMedium.h"
#include "TLitVolume.h"
#include "TLit.h"
#include "TLitPhoton.h"
#include "TLitSpontan.h"
#include "TLitranino.h"
#include "TLitResults.h"
#include "TLitMarrow.h"
#include "TLitParticle.h"
#include "TLitBeam.h"
#include "TLitCascade.h"
#include "TLitGamma.h"
#include "TLitAlbedo.h"
#include <algorithm>
namespace std { }
using namespace std;

#ifndef G__MEMFUNCBODY
#endif

extern G__linked_taginfo G__SLitraniDictLN_TClass;
extern G__linked_taginfo G__SLitraniDictLN_TBuffer;
extern G__linked_taginfo G__SLitraniDictLN_TMemberInspector;
extern G__linked_taginfo G__SLitraniDictLN_TObject;
extern G__linked_taginfo G__SLitraniDictLN_TNamed;
extern G__linked_taginfo G__SLitraniDictLN_TString;
extern G__linked_taginfo G__SLitraniDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR;
extern G__linked_taginfo G__SLitraniDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__SLitraniDictLN_TObjArray;
extern G__linked_taginfo G__SLitraniDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR;
extern G__linked_taginfo G__SLitraniDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__SLitraniDictLN_TComplex;
extern G__linked_taginfo G__SLitraniDictLN_TLitPol3;
extern G__linked_taginfo G__SLitraniDictLN_TLitPol4;
extern G__linked_taginfo G__SLitraniDictLN_TAttLine;
extern G__linked_taginfo G__SLitraniDictLN_TVectorTlEfloatgR;
extern G__linked_taginfo G__SLitraniDictLN_TVectorTlEdoublegR;
extern G__linked_taginfo G__SLitraniDictLN_TH1;
extern G__linked_taginfo G__SLitraniDictLN_TH1F;
extern G__linked_taginfo G__SLitraniDictLN_TGraph;
extern G__linked_taginfo G__SLitraniDictLN_TArrayD;
extern G__linked_taginfo G__SLitraniDictLN_TH1D;
extern G__linked_taginfo G__SLitraniDictLN_KindOfMessage;
extern G__linked_taginfo G__SLitraniDictLN_TypeOfEquation;
extern G__linked_taginfo G__SLitraniDictLN_TLitEqIndex;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTBaselEfloatgR;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTBaselEdoublegR;
extern G__linked_taginfo G__SLitraniDictLN_TElementActionTlEfloatgR;
extern G__linked_taginfo G__SLitraniDictLN_TElementPosActionTlEfloatgR;
extern G__linked_taginfo G__SLitraniDictLN_TElementActionTlEdoublegR;
extern G__linked_taginfo G__SLitraniDictLN_TElementPosActionTlEdoublegR;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTlEfloatgR;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTRow_constlEfloatgR;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTRowlEfloatgR;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTDiag_constlEfloatgR;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTColumn_constlEfloatgR;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTFlat_constlEfloatgR;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTSub_constlEfloatgR;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTSparseRow_constlEfloatgR;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTSparseDiag_constlEfloatgR;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTColumnlEfloatgR;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTDiaglEfloatgR;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTFlatlEfloatgR;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTSublEfloatgR;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTSparseRowlEfloatgR;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTSparseDiaglEfloatgR;
extern G__linked_taginfo G__SLitraniDictLN_TVector3;
extern G__linked_taginfo G__SLitraniDictLN_TVec3C;
extern G__linked_taginfo G__SLitraniDictLN_TMat33;
extern G__linked_taginfo G__SLitraniDictLN_Sharing;
extern G__linked_taginfo G__SLitraniDictLN_TLitWave;
extern G__linked_taginfo G__SLitraniDictLN_TLitPhoton;
extern G__linked_taginfo G__SLitraniDictLN_TFile;
extern G__linked_taginfo G__SLitraniDictLN_TLitHistParams;
extern G__linked_taginfo G__SLitraniDictLN_TRandom3;
extern G__linked_taginfo G__SLitraniDictLN_KindOfDist;
extern G__linked_taginfo G__SLitraniDictLN_EDepProcess;
extern G__linked_taginfo G__SLitraniDictLN_OpticalProcess;
extern G__linked_taginfo G__SLitraniDictLN_KindOfDet;
extern G__linked_taginfo G__SLitraniDictLN_TGeoMedium;
extern G__linked_taginfo G__SLitraniDictLN_TLitPhys;
extern G__linked_taginfo G__SLitraniDictLN_TGeoMatrix;
extern G__linked_taginfo G__SLitraniDictLN_TGeoVolume;
extern G__linked_taginfo G__SLitraniDictLN_TGeoTrap;
extern G__linked_taginfo G__SLitraniDictLN_TLitTrap;
extern G__linked_taginfo G__SLitraniDictLN_TLitSpectrumCp;
extern G__linked_taginfo G__SLitraniDictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR;
extern G__linked_taginfo G__SLitraniDictLN_TPolyMarker;
extern G__linked_taginfo G__SLitraniDictLN_TBranch;
extern G__linked_taginfo G__SLitraniDictLN_TTree;
extern G__linked_taginfo G__SLitraniDictLN_TSplineFit;
extern G__linked_taginfo G__SLitraniDictLN_TLitSpectrum;
extern G__linked_taginfo G__SLitraniDictLN_TH2;
extern G__linked_taginfo G__SLitraniDictLN_TH2F;
extern G__linked_taginfo G__SLitraniDictLN_TH2D;
extern G__linked_taginfo G__SLitraniDictLN_LitMemForDet;
extern G__linked_taginfo G__SLitraniDictLN_TLitDetector;
extern G__linked_taginfo G__SLitraniDictLN_TLitSellmeier;
extern G__linked_taginfo G__SLitraniDictLN_maplEintcOTGeoElementRNmUcOlesslEintgRcOallocatorlEpairlEconstsPintcOTGeoElementRNmUgRsPgRsPgR;
extern G__linked_taginfo G__SLitraniDictLN_TGeoMaterial;
extern G__linked_taginfo G__SLitraniDictLN_KindOfMedium;
extern G__linked_taginfo G__SLitraniDictLN_MethodUsed;
extern G__linked_taginfo G__SLitraniDictLN_dEdxMethod;
extern G__linked_taginfo G__SLitraniDictLN_TLitMedium;
extern G__linked_taginfo G__SLitraniDictLN_TMat33C;
extern G__linked_taginfo G__SLitraniDictLN_ChoiceOfn;
extern G__linked_taginfo G__SLitraniDictLN_TLitVolume;
extern G__linked_taginfo G__SLitraniDictLN_maplEstringcOTObjArraymUcOlesslEstringgRcOallocatorlEpairlEconstsPstringcOTObjArraymUgRsPgRsPgR;
extern G__linked_taginfo G__SLitraniDictLN_TReference;
extern G__linked_taginfo G__SLitraniDictLN_TLit;
extern G__linked_taginfo G__SLitraniDictLN_TAtt3D;
extern G__linked_taginfo G__SLitraniDictLN_TGeoNode;
extern G__linked_taginfo G__SLitraniDictLN_vectorlETGeoVolumeAssemblycLcLThreadData_tmUcOallocatorlETGeoVolumeAssemblycLcLThreadData_tmUgRsPgR;
extern G__linked_taginfo G__SLitraniDictLN_reverse_iteratorlEvectorlETGeoVolumeAssemblycLcLThreadData_tmUcOallocatorlETGeoVolumeAssemblycLcLThreadData_tmUgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__SLitraniDictLN_TVirtualGeoTrack;
extern G__linked_taginfo G__SLitraniDictLN_TGeoPhysicalNode;
extern G__linked_taginfo G__SLitraniDictLN_TLitResults;
extern G__linked_taginfo G__SLitraniDictLN_TLitMarrow;
extern G__linked_taginfo G__SLitraniDictLN_TLitSpontan;
extern G__linked_taginfo G__SLitraniDictLN_TLitranino;
extern G__linked_taginfo G__SLitraniDictLN_TPaveLabel;
extern G__linked_taginfo G__SLitraniDictLN_TPaveText;
extern G__linked_taginfo G__SLitraniDictLN_TParticle;
extern G__linked_taginfo G__SLitraniDictLN_PDistribution;
extern G__linked_taginfo G__SLitraniDictLN_TLitParticle;
extern G__linked_taginfo G__SLitraniDictLN_TLitBeam;
extern G__linked_taginfo G__SLitraniDictLN_TLitCascade;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTlEdoublegR;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTRow_constlEdoublegR;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTRowlEdoublegR;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTDiag_constlEdoublegR;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTColumn_constlEdoublegR;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTFlat_constlEdoublegR;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTSub_constlEdoublegR;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTSparseRow_constlEdoublegR;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTSparseDiag_constlEdoublegR;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTColumnlEdoublegR;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTDiaglEdoublegR;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTFlatlEdoublegR;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTSublEdoublegR;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTSparseRowlEdoublegR;
extern G__linked_taginfo G__SLitraniDictLN_TMatrixTSparseDiaglEdoublegR;
extern G__linked_taginfo G__SLitraniDictLN_pairlEunsignedsPintcOintgR;
extern G__linked_taginfo G__SLitraniDictLN_vectorlEpairlEunsignedsPintcOintgRcOallocatorlEpairlEunsignedsPintcOintgRsPgRsPgR;
extern G__linked_taginfo G__SLitraniDictLN_reverse_iteratorlEvectorlEpairlEunsignedsPintcOintgRcOallocatorlEpairlEunsignedsPintcOintgRsPgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__SLitraniDictLN_TLitGamma;
extern G__linked_taginfo G__SLitraniDictLN_TGeoTranslation;
extern G__linked_taginfo G__SLitraniDictLN_TLitAlbedo;

/* STUB derived class for protected member access */
