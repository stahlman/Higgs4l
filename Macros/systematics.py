systematics_temp = [
  #("ElectronScaleMatCryoEndcapDn",        "ATLAS_EM_MatCryo_EC"), 
  ("MuonResolutionMSDn",   "ATLAS_MU_RES_MS"),
]


# list of experimental systematics
# saved in form (my_systematic_name, official_atlas_nuisance_parameter_name) 

systematics_electron_scale = [

  ("ElectronScaleZeeAllUp",	       "ATLAS_EM_ES_Z"),
  ("ElectronScaleZeeAllDn",	       "ATLAS_EM_ES_Z"),
  #("ElectronScaleZeeStatUp",	       "ATLAS_EM_ES_ZStat"),
  #("ElectronScaleZeeStatDn",	       "ATLAS_EM_ES_ZStat"),
  #("ElectronScaleZeeSystUp",	       "ATLAS_EM_ES_ZSyst"),
  #("ElectronScaleZeeSystDn",	       "ATLAS_EM_ES_ZSyst"),
  ("ElectronScalePSBarrelUp", 	       "ATLAS_EM_PS_Barrel"), 
  ("ElectronScalePSBarrelDn", 	       "ATLAS_EM_PS_Barrel"), 
  ("ElectronScalePSEndcapUp", 	       "ATLAS_EM_PS_EC"), 
  ("ElectronScalePSEndcapDn", 	       "ATLAS_EM_PS_EC"), 
  ("ElectronScaleS12BarrelUp",	       "ATLAS_EM_S12_Barrel"),
  ("ElectronScaleS12BarrelDn",	       "ATLAS_EM_S12_Barrel"),
  ("ElectronScaleS12EndcapUp",	       "ATLAS_EM_S12_EC"),
  ("ElectronScaleS12EndcapDn",	       "ATLAS_EM_S12_EC"),
  ("ElectronScaleMatID1Up",	       "ATLAS_EM_MatID_1"),
  ("ElectronScaleMatID1Dn",	       "ATLAS_EM_MatID_1"),
  ("ElectronScaleMatID2Up",	       "ATLAS_EM_MatID_2"),
  ("ElectronScaleMatID2Dn",	       "ATLAS_EM_MatID_2"),
  ("ElectronScaleMatID3Up",	       "ATLAS_EM_MatID_3"),
  ("ElectronScaleMatID3Dn",	       "ATLAS_EM_MatID_3"),
  ("ElectronScaleMatID4Up",	       "ATLAS_EM_MatID_4"),
  ("ElectronScaleMatID4Dn",	       "ATLAS_EM_MatID_4"),
  ("ElectronScaleMatCryoBarrelUp",        "ATLAS_EM_MatCryo_Barrel"), 
  ("ElectronScaleMatCryoBarrelDn",        "ATLAS_EM_MatCryo_Barrel"), 
  ("ElectronScaleMatCryoEndcapUp",        "ATLAS_EM_MatCryo_EC"), 
  ("ElectronScaleMatCryoEndcapDn",        "ATLAS_EM_MatCryo_EC"), 
  ("ElectronScaleMatCaloBarrelUp",        "ATLAS_EM_MatCalo_Barrel"), 
  ("ElectronScaleMatCaloBarrelDn",        "ATLAS_EM_MatCalo_Barrel"), 
  ("ElectronScaleMatCaloEndcapUp",        "ATLAS_EM_MatCalo_EC"), 
  ("ElectronScaleMatCaloEndcapDn",        "ATLAS_EM_MatCalo_EC"), 
  ("ElectronScaleLArCalibBarrelUp",       "ATLAS_EM_LArCalib_Barrel"),
  ("ElectronScaleLArCalibBarrelDn",       "ATLAS_EM_LArCalib_Barrel"),
  ("ElectronScaleLArCalibEndcapUp",       "ATLAS_EM_LArCalib_EC"),
  ("ElectronScaleLArCalibEndcapDn",       "ATLAS_EM_LArCalib_EC"),
  ("ElectronScaleLArUnconvCalibBarrelUp", "ATLAS_EM_LArUnconvCalib_Barrel"),
  ("ElectronScaleLArUnconvCalibBarrelDn", "ATLAS_EM_LArUnconvCalib_Barrel"),
  ("ElectronScaleLArUnconvCalibEndcapUp", "ATLAS_EM_LArUnconvCalib_EC"),
  ("ElectronScaleLArUnconvCalibEndcapDn", "ATLAS_EM_LArUnconvCalib_EC"),
  ("ElectronScaleLArElecUnconvBarrelUp",  "ATLAS_EM_LArElecUnconv_Barrel"), 
  ("ElectronScaleLArElecUnconvBarrelDn",  "ATLAS_EM_LArElecUnconv_Barrel"), 
  ("ElectronScaleLArElecUnconvEndcapUp",  "ATLAS_EM_LArElecUnconv_EC"), 
  ("ElectronScaleLArElecUnconvEndcapDn",  "ATLAS_EM_LArElecUnconv_EC"), 
  ("ElectronScaleLArElecCalibUp",  	  "ATLAS_EM_LArElecCalib"), 
  ("ElectronScaleLArElecCalibDn",  	  "ATLAS_EM_LArElecCalib"), 
  ("ElectronScaleL1GainUp",		       "ATLAS_EM_L1Gain"),
  ("ElectronScaleL1GainDn",		       "ATLAS_EM_L1Gain"),
  ("ElectronScaleL2GainUp",		       "ATLAS_EM_L2Gain"),
  ("ElectronScaleL2GainDn",		       "ATLAS_EM_L2Gain"),
  ("ElectronScaleG4Up",		       "ATLAS_EM_Geant4"),
  ("ElectronScaleG4Dn",		       "ATLAS_EM_Geant4"),
  ("ElectronScalePedestalUp",	       "ATLAS_EM_Pedestal"),
  ("ElectronScalePedestalDn",	       "ATLAS_EM_Pedestal"),
  ("ElectronScaleMomentumUp",	       "ATLAS_EM_ES_Momentum"),
  ("ElectronScaleMomentumDn",	       "ATLAS_EM_ES_Momentum"),
]

systematics_electron_resolution = [

   ("ElectronResolutionZSmearingUp",     "ATLAS_EM_mRes_CT"),
   ("ElectronResolutionZSmearingDn",     "ATLAS_EM_mRes_CT"),       
   ("ElectronResolutionSamplingTermUp",  "ATLAS_EM_mRes_ST"), 
   ("ElectronResolutionSamplingTermDn",  "ATLAS_EM_mRes_ST"), 
   ("ElectronResolutionMaterialIDUp",    "ATLAS_EM_mRes_MaterialID"),	#collapse these systs into one MAT systematic??
   ("ElectronResolutionMaterialIDDn",    "ATLAS_EM_mRes_MaterialID"),  
   ("ElectronResolutionMaterialCaloUp",  "ATLAS_EM_mRes_MaterialCalo"), 
   ("ElectronResolutionMaterialCaloDn",  "ATLAS_EM_mRes_MaterialCalo"), 
   ("ElectronResolutionMaterialGapUp",   "ATLAS_EM_mRes_MaterialGap"),  
   ("ElectronResolutionMaterialGapDn",   "ATLAS_EM_mRes_MaterialGap"), 
   ("ElectronResolutionMaterialCryoUp",  "ATLAS_EM_mRes_MaterialCryo"), 
   ("ElectronResolutionMaterialCryoDn",  "ATLAS_EM_mRes_MaterialCryo"), 
   ("ElectronResolutionPileUpUp",	 "ATLAS_EM_mRes_PU"),    
   ("ElectronResolutionPileUpDn",	 "ATLAS_EM_mRes_PU"),    

]

systematics_muon_scale = [

  ("MuonScaleUp",  "ATLAS_MU_MS"),
  ("MuonScaleDn",  "ATLAS_MU_MS"),

]

systematics_muon_resolution = [

  #("MuonResolutionMSUp",   "ATLAS_MU_RES_MS"),
  ("MuonResolutionMSDn",   "ATLAS_MU_RES_MS"),
  ("MuonResolutionIDUp",   "ATLAS_MU_RES_ID"),
  ("MuonResolutionIDDn",   "ATLAS_MU_RES_ID"),

]

systematics_all_scale_resolution = systematics_muon_resolution + systematics_muon_scale + systematics_electron_resolution + systematics_electron_scale


systematics_electron_efficiency = [

  ('ElectronRecoLow',    'ATLAS_EL_2012_REC_low'), 
  ('ElectronRecoHigh',   'ATLAS_EL_2012_REC_high'),
  ('ElectronIDLow',      'ATLAS_EL_2012_ID_low'),   
  ('ElectronStat15',     'ATLAS_EL_2012_ST_15'),  
  ('ElectronStat10',     'ATLAS_EL_2012_ST_10'),  
  ('ElectronStat7',      'ATLAS_EL_2012_ST_7'),   
  ('ElectronIDStatHigh',  'ATLAS_EL_2012_IDST_high'),
  ('ElectronTrigger',    'ATLAS_EL_2012_TRIG'), 
  ('ElectronIsoIP',      'ATLAS_EL_ISO_HZZ'),   

]

systematics_muon_efficiency = [

  ('MuonRecoID',  'ATLAS_MU_EFF'),
  ('MuonTrigger', 'ATLAS_MU_2012_TRIG'),

]

systematics_jet_efficiency = [

  ('JVFUp', 'ATLAS_JVF_2012'),
  ('JVFDn', 'ATLAS_JVF_2012'),
  
]

systematics_jet_scale = [

  ('JES_Statistical1Up',    'ATLAS_JES_2012_Statistical1'),
  ('JES_Statistical1Dn',    'ATLAS_JES_2012_Statistical1'),
  ('JES_Statistical2Up',    'ATLAS_JES_2012_Statistical2'),
  ('JES_Statistical2Dn',    'ATLAS_JES_2012_Statistical2'),
  ('JES_Statistical3Up',    'ATLAS_JES_2012_Statistical3'),
  ('JES_Statistical3Dn',    'ATLAS_JES_2012_Statistical3'),
  ('JES_Modelling1Up',	   'ATLAS_JES_2012_Modelling1'),
  ('JES_Modelling1Dn',	   'ATLAS_JES_2012_Modelling1'),
  ('JES_Modelling2Up',	   'ATLAS_JES_2012_Modelling2'),
  ('JES_Modelling2Dn',	   'ATLAS_JES_2012_Modelling2'),
  ('JES_Modelling3Up',	   'ATLAS_JES_2012_Modelling3'),
  ('JES_Modelling3Dn',	   'ATLAS_JES_2012_Modelling3'),
  ('JES_Modelling4Up',	   'ATLAS_JES_2012_Modelling4'),
  ('JES_Modelling4Dn',	   'ATLAS_JES_2012_Modelling4'),
  ('JES_Detector1Up',	   'ATLAS_JES_2012_Detector1'),
  ('JES_Detector1Dn',	   'ATLAS_JES_2012_Detector1'),
  ('JES_Detector2Up',	   'ATLAS_JES_2012_Detector2'),
  ('JES_Detector2Dn',	   'ATLAS_JES_2012_Detector2'),
  ('JES_Detector3Up',	   'ATLAS_JES_2012_Detector3'),
  ('JES_Detector3Dn',	   'ATLAS_JES_2012_Detector3'),
  ('JES_Mixed1Up',	   'ATLAS_JES_2012_Mixed1'),
  ('JES_Mixed1Dn',	   'ATLAS_JES_2012_Mixed1'),
  ('JES_Mixed2Up',	   'ATLAS_JES_2012_Mixed2'),
  ('JES_Mixed2Dn',	   'ATLAS_JES_2012_Mixed2'),
  ('JES_Eta_ModellingUp',   'ATLAS_JES_Eta_Modelling'),
  ('JES_Eta_ModellingDn',   'ATLAS_JES_Eta_Modelling'),
  ('JES_Eta_StatMethodUp',  'ATLAS_JES_2012_Eta_StatMethod'),
  ('JES_Eta_StatMethodDn',  'ATLAS_JES_2012_Eta_StatMethod'),
  ('JES_HighPtUp',	   'ATLAS_JES_HighPt'),
  ('JES_HighPtDn',	   'ATLAS_JES_HighPt'),
  ('JES_NPVUp',		   'ATLAS_JES_NPV'),
  ('JES_NPVDn',		   'ATLAS_JES_NPV'),
  ('JES_MuUp',		   'ATLAS_JES_Mu'),
  ('JES_MuDn',		   'ATLAS_JES_Mu'),
  ('JES_PilePtUp',	   'ATLAS_JES_2012_PilePt'),
  ('JES_PilePtDn',	   'ATLAS_JES_2012_PilePt'),
  ('JES_PileRho_ANA_BGUp',  'ATLAS_JES_2012_PileRho_ANA_BG'),
  ('JES_PileRho_ANA_BGDn',  'ATLAS_JES_2012_PileRho_ANA_BG'),
  ('JES_ClosebyUp',	   'ATLAS_JES_Closeby'),
  ('JES_ClosebyDn',	   'ATLAS_JES_Closeby'),
  ('JES_FlavComp_ANA_BGUp', 'ATLAS_JES_FlavComp_ANA_BG'),
  ('JES_FlavComp_ANA_BGDn', 'ATLAS_JES_FlavComp_ANA_BG'),
  ('JES_FlavRespUp',	   'ATLAS_JES_FlavResp'),
  ('JES_FlavRespDn',	   'ATLAS_JES_FlavResp'),

]

systematics_jet_resolution = [

  ('JER_Resolution', 'ATLAS_JER'),

]

systematics_jet_all = systematics_jet_efficiency + systematics_jet_scale + systematics_jet_resolution
systematics_muon_all = systematics_muon_efficiency + systematics_muon_scale + systematics_muon_resolution
systematics_electron_all = systematics_electron_efficiency + systematics_electron_scale + systematics_electron_resolution

systematics_all = systematics_electron_all + systematics_muon_all + systematics_jet_all
