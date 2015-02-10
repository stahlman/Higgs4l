
INPUTDIR=/disk/userdata00/atlas_data2/stahlman/output/23012014/


#for SYSTEMATIC in MuonResolutionMSUp MuonResolutionMSDn MuonResolutionIDUp MuonResolutionIDDn MuonScaleUp MuonScaleDn ElectronScaleZeeUp ElectronScaleZeeDn ElectronScaleR12Up ElectronScaleR12Dn ElectronScalePSUp ElectronScalePSDn ElectronScaleLowPtUp ElectronScaleLowPtDn ElectronResolutionUp ElectronResolutionDn 
#do
#  for SAMPLE in ggH125 VBFH125 WH125 ZH125 ttH125
#  do       
#       python makeMiniTrees.py --dir $INPUTDIR --keys $SAMPLE\_$SYSTEMATIC --out $INPUTDIR\minitrees --tag Systematic --syst
#  done
#done  

SAMPLES=`ls -l $INPUTDIR | egrep '^d' | awk '{print $9}'`
  
python makeMiniTrees.py --dir $INPUTDIR --keys $SAMPLES --out $INPUTDIR\minitrees --tag Systematic --syst
