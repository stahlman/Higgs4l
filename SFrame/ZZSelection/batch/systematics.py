systematics_electron_scale = [

  "ElectronScaleZeeStatUp",
  "ElectronScaleZeeStatDn",
  "ElectronScaleZeeSystUp",
  "ElectronScaleZeeSystDn",
  "ElectronScalePSBarrelUp", 
  "ElectronScalePSBarrelDn", 
  "ElectronScalePSEndcapUp", 
  "ElectronScalePSEndcapDn", 
  "ElectronScaleS12BarrelUp",
  "ElectronScaleS12BarrelDn",
  "ElectronScaleS12EndcapUp",
  "ElectronScaleS12EndcapDn",
  "ElectronScaleMatID1Up",
  "ElectronScaleMatID1Dn",
  "ElectronScaleMatID2Up",
  "ElectronScaleMatID2Dn",
  "ElectronScaleMatID3Up",
  "ElectronScaleMatID3Dn",
  "ElectronScaleMatID4Up",
  "ElectronScaleMatID4Dn",
  "ElectronScaleMatCryoBarrelUp", 
  "ElectronScaleMatCryoBarrelDn", 
  "ElectronScaleMatCryoEndcapUp", 
  "ElectronScaleMatCryoEndcapDn", 
  "ElectronScaleMatCaloBarrelUp", 
  "ElectronScaleMatCaloBarrelDn", 
  "ElectronScaleMatCaloEndcapUp", 
  "ElectronScaleMatCaloEndcapDn", 
  "ElectronScaleLArCalibBarrelUp",
  "ElectronScaleLArCalibBarrelDn",
  "ElectronScaleLArCalibEndcapUp",
  "ElectronScaleLArCalibEndcapDn",
  "ElectronScaleLArUnconvCalibBarrelUp",
  "ElectronScaleLArUnconvCalibBarrelDn",
  "ElectronScaleLArUnconvCalibEndcapUp",
  "ElectronScaleLArUnconvCalibEndcapDn",
  "ElectronScaleLArElecUnconvBarrelUp", 
  "ElectronScaleLArElecUnconvBarrelDn", 
  "ElectronScaleLArElecUnconvEndcapUp", 
  "ElectronScaleLArElecUnconvEndcapDn", 
  "ElectronScaleGainUp",
  "ElectronScaleGainDn",
  "ElectronScaleG4Up",
  "ElectronScaleG4Dn",
]

systematics_electron_resolution = [

  "ElectronResolutionZSmearingDn",   
  "ElectronResolutionSamplingTermUp", 
  "ElectronResolutionSamplingTermDn", 
  "ElectronResolutionMaterialIDUp",   
  "ElectronResolutionMaterialIDDn",  
  "ElectronResolutionMaterialCaloUp", 
  "ElectronResolutionMaterialCaloDn", 
  "ElectronResolutionMaterialGapUp",  
  "ElectronResolutionMaterialGapDn", 
  "ElectronResolutionMaterialCryoUp", 
  "ElectronResolutionMaterialCryoDn", 
  "ElectronResolutionPileUpUp",	   
  "ElectronResolutionPileUpDn",	   

]

systematics_muon_scale = [

  "MuonScaleUp", 
  "MuonScaleDn"

]

systematics_muon_resolution = [

  "MuonResolutionMSDn", 
  "MuonResolutionIDUp", 
  "MuonResolutionIDDn", 

]

systematics_all = systematics_muon_resolution + systematics_muon_scale + systematics_electron_resolution + systematics_electron_scale
