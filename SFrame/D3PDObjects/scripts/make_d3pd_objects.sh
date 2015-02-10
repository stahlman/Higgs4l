#!/bin/bash                                                                       
#author Justin Griffiths                                                          

# used asetup 16.6.2                                                              

# This application can be used to generate D3PDReader classes                     
# based on an existing D3PD file and some additional command                      
# line options:                                                                   
#   -h [ --help ]                        Give some help with the program usage    
#   -n [ --classname ] arg (=D3PDReader) Generated class name                     
#   -f [ --d3pd-file ] arg               Input D3PD file                          
#   -t [ --tree ] arg                    Name of the D3PD tree                    
#   -v [ --variables ] arg               Variable names to consider               
#   -p [ --prefix ] arg                  Variable name prefix                     
#   -c [ --container ]                   Option specifying that a proxy class     
#                                        should be created                        
#   -o [ --output ] arg (=./)            Output directory for the generated       
#                                        source files                             

outdir=D3PDObjects/

if [[ $1 ]]; then
    rm $outdir/*.cxx $outdir/*.h $outdir/*.icc
    return
fi

#file=/tmp/kadlecik/group10.perf-tau.10595_003756.StreamD3PD_TauMEDIUM._00066.root                                                                                 
#file=/local_data0/olivito/data/WZElec/group10.phys-sm.mc10_7TeV.105603.Pythia_Zprime_ee_SSM1000.merge.AOD.e574_s933_s946_r1831_r1700.WZphys.101222.01.D3PD.110104230612/group10.phys-sm.08816_003750.D3PD._00001.root                              
#file=/local_data0/olivito/data/Egamma/data11_7TeV.00178044.physics_Egamma.merge.NTUP_EGAMMA.f354_m765_p466_tid289481_00/NTUP_EGAMMA.289481._000053.root.1         
#file=/local_data0/olivito/data/ElectronPreselCycle/data11_7TeV.00178109.physics_Egamma.merge.NTUP_SMWZ.f354_m765_p471_tid290458_00/NTUP_SMWZ.290458._000005.root.1                                                                                 
#file=/local_data0/olivito/data/SMWZ/data11_7TeV.00179710.physics_Egamma.merge.NTUP_SMWZ.f361_m796_p503_tid309684_00/NTUP_SMWZ.309684._000037.root.1               
#file=/local_data0/olivito/data/SMWZ/data11_7TeV.00180614.physics_Egamma.merge.NTUP_SMWZ.f369_m812_p503_tid336040_00/NTUP_SMWZ.336040._000037.root.1
#file=/local_data0/olivito/data/SMWZ/mc10_7TeV.105722.PythiaB_bbe7X.merge.NTUP_SMWZ.e574_s933_s946_r2304_r2300_p574_tid368372_00/NTUP_SMWZ.368372._000068.root.1   
#file=/local_data0/olivito/data/Egamma/valid1.106046.PythiaZee_no_filter.merge.NTUP_EGAMMA.e603_s932_r2085_p492_tid307301_00/NTUP_EGAMMA.307301._000004.root.1     
#alias d3pd_command='./d3pdReaderMaker.exe -t physics -f $file -o D3PDObjects/ -n

#file=/local_data0/jdegenha/MET_Perf/NTUP_JETMETWZ_egamma_temp.root
file=/

tree=physics

./d3pdReaderMaker.exe -t $tree -f $file -o $outdir -n EventInfoD3PDObject -v '^RunNumber$' '^EventNumber$' '^timestamp$' '^timestamp_ns$' '^lbn$' '^bcid$' '^detmask0$' '^detmask1$' '^pixelFlags$' '^sctFlags$' '^trtFlags$' '^larFlags$' '^tileFlags$' '^muonFlags$' '^fwdFlags$' '^coreFlags$' '^pixelError$' '^sctError$' '^trtError$' '^larError$' '^tileError$' '^muonError$' '^fwdError$' '^coreError$'
#./d3pdReaderMaker.exe -t $tree -f $file -o $outdir -n ElectronD3PDObject -p 'el_' -v "^el_(?"'!'"MET_n).*" -c                                                     
./d3pdReaderMaker.exe -t $tree -f $file -o $outdir -n ElectronD3PDObject -p 'el_' -v '^el_.*' -c
./d3pdReaderMaker.exe -t $tree -f $file -o $outdir -n PhotonD3PDObject -p 'ph_' -v '^ph_.*' -c
./d3pdReaderMaker.exe -t $tree -f $file -o $outdir -n JetD3PDObject -p 'jet_akt4topoem_' -v '^jet_akt4topoem_.*' -c
./d3pdReaderMaker.exe -t $tree -f $file -o $outdir -n METD3PDObject -p 'MET_' -v '^MET_.*'
./d3pdReaderMaker.exe -t $tree -f $file -o $outdir -n MuonStacoD3PDObject -p 'mu_staco_' -v '^mu_staco_.*' -c
./d3pdReaderMaker.exe -t $tree -f $file -o $outdir -n MuonD3PDObject -p 'mu_staco_' -v '^mu_.*' -c
./d3pdReaderMaker.exe -t $tree -f $file -o $outdir -n TauD3PDObject -p 'tau_' -v '^tau_.*' -c
#./d3pdReaderMaker.exe -t $tree -f $file -o $outdir -n TrigDecisionD3PDObject -p 'trig_' -v '^trig_((EF|L2|Nav|DB)_(passed|chain|SMK|L1PSK|HLTPSK).*)|(RoI_EF_(mu_TrigMuonEFInfoContainer|e_egammaContainer_egamma_Electrons|tau_Analysis::TauJetCon\
#tainer).*)'
#./d3pdReaderMaker.exe -t $tree -f $file -o $outdir -n TrigEFelD3PDObject -p 'trig_EF_el_' -v '^trig_EF_el_.*' -c
#./d3pdReaderMaker.exe -t $tree -f $file -o $outdir -n TrigEFmuD3PDObject -p 'trig_EF_trigmuonef_' -v '^trig_EF_trigmuonef_.*' -c
#./d3pdReaderMaker.exe -t $tree -f $file -o $outdir -n TrigEFtauD3PDObject -p 'trig_EF_tau_' -v '^trig_EF_tau_.*' -c
./d3pdReaderMaker.exe -t $tree -f $file -o $outdir -n TriggerD3PDObject -v '^EF_.*e.*' '^EF_.*g.*' '^L1_EM.*'
./d3pdReaderMaker.exe -t $tree -f $file -o $outdir -n TruthD3PDObject -p 'mc_' -v '^mc_.*' -c
./d3pdReaderMaker.exe -t $tree -f $file -o $outdir -n VxpD3PDObject -p 'vxp_' -v '^vxp_.*' -c
#./d3pdReaderMaker.exe -t $tree -f $file -o $outdir -n TrigMETD3PDObject -p 'trig_' -v '^trig_(EF|L2)_met_.*'
./d3pdReaderMaker.exe -t $tree -f $file -o $outdir -n MCEvtD3PDObject -p 'mcevt_' -v '^mcevt_.*'

cd $outdir

for f in $( ls *.cxx); do
    class_name=`echo $f | sed 's,\.cxx,,g'`
    sed -i 's,#include "'$class_name'.h",#include "../include/'$class_name'.h",g' $f
done

cd ..
