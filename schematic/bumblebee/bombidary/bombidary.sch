<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.2.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="USB_pcb_connectors">
<packages>
<package name="USB_TYPE_C_DS_1">
<wire x1="-3.345" y1="0" x2="-3.045" y2="0" width="0" layer="51"/>
<wire x1="-3.045" y1="0" x2="3.045" y2="0" width="0" layer="20"/>
<wire x1="3.045" y1="0" x2="3.345" y2="0" width="0" layer="51"/>
<wire x1="-3.345" y1="0" x2="-3.345" y2="-0.75" width="0" layer="51"/>
<wire x1="-3.345" y1="-0.75" x2="-3.345" y2="-1.25" width="0" layer="20"/>
<wire x1="-3.345" y1="-1.25" x2="-3.345" y2="-2.75" width="0" layer="51"/>
<wire x1="3.345" y1="0" x2="3.345" y2="-0.75" width="0" layer="51"/>
<wire x1="3.345" y1="-0.75" x2="3.345" y2="-1.25" width="0" layer="20"/>
<wire x1="3.345" y1="-1.25" x2="3.345" y2="-2.75" width="0" layer="51"/>
<wire x1="-3.045" y1="0" x2="-3.345" y2="-0.75" width="0" layer="20"/>
<wire x1="-3.095" y1="-1.5" x2="-3.095" y2="-2.5" width="0" layer="20"/>
<wire x1="-3.095" y1="-2.5" x2="-3.345" y2="-2.75" width="0" layer="20" curve="-90"/>
<wire x1="-3.095" y1="-1.5" x2="-3.345" y2="-1.25" width="0" layer="20" curve="90"/>
<wire x1="3.095" y1="-1.5" x2="3.095" y2="-2.5" width="0" layer="20"/>
<wire x1="3.095" y1="-2.5" x2="3.345" y2="-2.75" width="0" layer="20" curve="90"/>
<wire x1="3.095" y1="-1.5" x2="3.345" y2="-1.25" width="0" layer="20" curve="-90"/>
<wire x1="3.045" y1="0" x2="3.345" y2="-0.75" width="0" layer="20"/>
<wire x1="3.345" y1="-2.75" x2="3.345" y2="-4.45" width="0" layer="20"/>
<wire x1="-3.345" y1="-2.75" x2="-3.345" y2="-4.45" width="0" layer="20"/>
<smd name="A11" x="-2.25" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A10" x="-1.75" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A8" x="-0.75" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A7" x="-0.25" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A6" x="0.25" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A5" x="0.75" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A3" x="1.75" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A2" x="2.25" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A12" x="-2.75" y="-2.45" dx="4" dy="0.25" layer="1" rot="R90"/>
<smd name="A9" x="-1.25" y="-2.45" dx="4" dy="0.25" layer="1" rot="R90"/>
<smd name="A4" x="1.25" y="-2.45" dx="4" dy="0.25" layer="1" rot="R90"/>
<smd name="A1" x="2.75" y="-2.45" dx="4" dy="0.25" layer="1" rot="R90"/>
<smd name="B1" x="-2.75" y="-2.45" dx="4" dy="0.25" layer="16" rot="R90"/>
<smd name="B4" x="-1.25" y="-2.45" dx="4" dy="0.25" layer="16" rot="R90"/>
<smd name="B9" x="1.25" y="-2.45" dx="4" dy="0.25" layer="16" rot="R90"/>
<smd name="B12" x="2.75" y="-2.45" dx="4" dy="0.25" layer="16" rot="R90"/>
<smd name="B2" x="-2.25" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B3" x="-1.75" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B5" x="-0.75" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B6" x="-0.25" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B7" x="0.25" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B8" x="0.75" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B10" x="1.75" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B11" x="2.25" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<wire x1="-7" y1="0" x2="-4.325" y2="0" width="0" layer="20"/>
<wire x1="-4.325" y1="0" x2="-4.125" y2="-0.2" width="0" layer="20" curve="-90"/>
<wire x1="-4.125" y1="-0.2" x2="-4.125" y2="-4.45" width="0" layer="20"/>
<wire x1="7" y1="0" x2="4.325" y2="0" width="0" layer="20"/>
<wire x1="4.325" y1="0" x2="4.125" y2="-0.2" width="0" layer="20" curve="90"/>
<wire x1="4.125" y1="-0.2" x2="4.125" y2="-4.45" width="0" layer="20"/>
<wire x1="-4.125" y1="-4.45" x2="-3.345" y2="-4.45" width="0" layer="20"/>
<wire x1="3.345" y1="-4.45" x2="4.125" y2="-4.45" width="0" layer="20"/>
</package>
<package name="USB_TYPE_C_DS_2">
<wire x1="-3.345" y1="0" x2="-3.045" y2="0" width="0" layer="51"/>
<wire x1="-3.045" y1="0" x2="3.045" y2="0" width="0" layer="20"/>
<wire x1="3.045" y1="0" x2="3.345" y2="0" width="0" layer="51"/>
<wire x1="-3.345" y1="0" x2="-3.345" y2="-0.75" width="0" layer="51"/>
<wire x1="-3.345" y1="-0.75" x2="-3.345" y2="-1.25" width="0" layer="20"/>
<wire x1="-3.345" y1="-1.25" x2="-3.345" y2="-2.75" width="0" layer="51"/>
<wire x1="3.345" y1="0" x2="3.345" y2="-0.75" width="0" layer="51"/>
<wire x1="3.345" y1="-0.75" x2="3.345" y2="-1.25" width="0" layer="20"/>
<wire x1="3.345" y1="-1.25" x2="3.345" y2="-2.75" width="0" layer="51"/>
<wire x1="-3.045" y1="0" x2="-3.345" y2="-0.75" width="0" layer="20"/>
<wire x1="-3.095" y1="-1.5" x2="-3.095" y2="-2.5" width="0" layer="20"/>
<wire x1="-3.095" y1="-2.5" x2="-3.345" y2="-2.75" width="0" layer="20" curve="-90"/>
<wire x1="-3.095" y1="-1.5" x2="-3.345" y2="-1.25" width="0" layer="20" curve="90"/>
<wire x1="3.095" y1="-1.5" x2="3.095" y2="-2.5" width="0" layer="20"/>
<wire x1="3.095" y1="-2.5" x2="3.345" y2="-2.75" width="0" layer="20" curve="90"/>
<wire x1="3.095" y1="-1.5" x2="3.345" y2="-1.25" width="0" layer="20" curve="-90"/>
<wire x1="3.045" y1="0" x2="3.345" y2="-0.75" width="0" layer="20"/>
<wire x1="3.345" y1="-2.75" x2="3.345" y2="-4.45" width="0" layer="20"/>
<wire x1="-3.345" y1="-2.75" x2="-3.345" y2="-4.45" width="0" layer="20"/>
<smd name="A11" x="-2.25" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A10" x="-1.75" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A8" x="-0.75" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A7" x="-0.25" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A6" x="0.25" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A5" x="0.75" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A3" x="1.75" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A2" x="2.25" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A12" x="-2.75" y="-2.45" dx="4" dy="0.25" layer="1" rot="R90"/>
<smd name="A9" x="-1.25" y="-2.45" dx="4" dy="0.25" layer="1" rot="R90"/>
<smd name="A4" x="1.25" y="-2.45" dx="4" dy="0.25" layer="1" rot="R90"/>
<smd name="A1" x="2.75" y="-2.45" dx="4" dy="0.25" layer="1" rot="R90"/>
<smd name="B1" x="-2.75" y="-2.45" dx="4" dy="0.25" layer="16" rot="R90"/>
<smd name="B4" x="-1.25" y="-2.45" dx="4" dy="0.25" layer="16" rot="R90"/>
<smd name="B9" x="1.25" y="-2.45" dx="4" dy="0.25" layer="16" rot="R90"/>
<smd name="B12" x="2.75" y="-2.45" dx="4" dy="0.25" layer="16" rot="R90"/>
<smd name="B2" x="-2.25" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B3" x="-1.75" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B5" x="-0.75" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B6" x="-0.25" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B7" x="0.25" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B8" x="0.75" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B10" x="1.75" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B11" x="2.25" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<wire x1="-7" y1="0" x2="-4.325" y2="0" width="0" layer="20"/>
<wire x1="-4.325" y1="0" x2="-4.125" y2="-0.2" width="0" layer="20" curve="-90"/>
<wire x1="-4.125" y1="-0.2" x2="-4.125" y2="-4.45" width="0" layer="20"/>
<wire x1="7" y1="0" x2="4.325" y2="0" width="0" layer="20"/>
<wire x1="4.325" y1="0" x2="4.125" y2="-0.2" width="0" layer="20" curve="90"/>
<wire x1="4.125" y1="-0.2" x2="4.125" y2="-4.45" width="0" layer="20"/>
<wire x1="-4.125" y1="-4.45" x2="-3.345" y2="-4.45" width="0" layer="20" curve="180"/>
<wire x1="3.345" y1="-4.45" x2="4.125" y2="-4.45" width="0" layer="20" curve="180"/>
</package>
<package name="USB_TYPE_C_DS_3">
<wire x1="-3.345" y1="0" x2="-3.045" y2="0" width="0" layer="51"/>
<wire x1="-3.045" y1="0" x2="3.045" y2="0" width="0" layer="20"/>
<wire x1="3.045" y1="0" x2="3.345" y2="0" width="0" layer="51"/>
<wire x1="-3.345" y1="0" x2="-3.345" y2="-0.75" width="0" layer="51"/>
<wire x1="-3.345" y1="-0.75" x2="-3.345" y2="-1.25" width="0" layer="20"/>
<wire x1="-3.345" y1="-1.25" x2="-3.345" y2="-2.75" width="0" layer="51"/>
<wire x1="3.345" y1="0" x2="3.345" y2="-0.75" width="0" layer="51"/>
<wire x1="3.345" y1="-0.75" x2="3.345" y2="-1.25" width="0" layer="20"/>
<wire x1="3.345" y1="-1.25" x2="3.345" y2="-2.75" width="0" layer="51"/>
<wire x1="-3.045" y1="0" x2="-3.345" y2="-0.75" width="0" layer="20"/>
<wire x1="-3.095" y1="-1.5" x2="-3.095" y2="-2.5" width="0" layer="20"/>
<wire x1="-3.095" y1="-2.5" x2="-3.345" y2="-2.75" width="0" layer="20" curve="-90"/>
<wire x1="-3.095" y1="-1.5" x2="-3.345" y2="-1.25" width="0" layer="20" curve="90"/>
<wire x1="3.095" y1="-1.5" x2="3.095" y2="-2.5" width="0" layer="20"/>
<wire x1="3.095" y1="-2.5" x2="3.345" y2="-2.75" width="0" layer="20" curve="90"/>
<wire x1="3.095" y1="-1.5" x2="3.345" y2="-1.25" width="0" layer="20" curve="-90"/>
<wire x1="3.045" y1="0" x2="3.345" y2="-0.75" width="0" layer="20"/>
<wire x1="3.345" y1="-2.75" x2="3.345" y2="-4.45" width="0" layer="20"/>
<wire x1="-3.345" y1="-2.75" x2="-3.345" y2="-4.45" width="0" layer="20"/>
<smd name="A11" x="-2.25" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A10" x="-1.75" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A8" x="-0.75" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A7" x="-0.25" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A6" x="0.25" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A5" x="0.75" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A3" x="1.75" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A2" x="2.25" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A12" x="-2.75" y="-2.45" dx="4" dy="0.25" layer="1" rot="R90"/>
<smd name="A9" x="-1.25" y="-2.45" dx="4" dy="0.25" layer="1" rot="R90"/>
<smd name="A4" x="1.25" y="-2.45" dx="4" dy="0.25" layer="1" rot="R90"/>
<smd name="A1" x="2.75" y="-2.45" dx="4" dy="0.25" layer="1" rot="R90"/>
<smd name="B1" x="-2.75" y="-2.45" dx="4" dy="0.25" layer="16" rot="R90"/>
<smd name="B4" x="-1.25" y="-2.45" dx="4" dy="0.25" layer="16" rot="R90"/>
<smd name="B9" x="1.25" y="-2.45" dx="4" dy="0.25" layer="16" rot="R90"/>
<smd name="B12" x="2.75" y="-2.45" dx="4" dy="0.25" layer="16" rot="R90"/>
<smd name="B2" x="-2.25" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B3" x="-1.75" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B5" x="-0.75" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B6" x="-0.25" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B7" x="0.25" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B8" x="0.75" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B10" x="1.75" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B11" x="2.25" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<wire x1="-8" y1="0" x2="-6.085" y2="0" width="0" layer="20"/>
<wire x1="-6.085" y1="0" x2="-5.885" y2="-0.2" width="0" layer="20" curve="-90"/>
<wire x1="-5.885" y1="-0.2" x2="-5.885" y2="-4.45" width="0" layer="20"/>
<wire x1="8" y1="0" x2="6.085" y2="0" width="0" layer="20"/>
<wire x1="6.085" y1="0" x2="5.885" y2="-0.2" width="0" layer="20" curve="90"/>
<wire x1="5.885" y1="-0.2" x2="5.885" y2="-4.45" width="0" layer="20"/>
<wire x1="-5.885" y1="-4.45" x2="-3.345" y2="-4.45" width="0" layer="20" curve="180"/>
<wire x1="3.345" y1="-4.45" x2="5.885" y2="-4.45" width="0" layer="20" curve="180"/>
</package>
<package name="USB_TYPE_C_DS_4">
<wire x1="-3.345" y1="0" x2="-3.045" y2="0" width="0" layer="51"/>
<wire x1="-3.045" y1="0" x2="3.045" y2="0" width="0" layer="20"/>
<wire x1="3.045" y1="0" x2="3.345" y2="0" width="0" layer="51"/>
<wire x1="-3.345" y1="0" x2="-3.345" y2="-0.75" width="0" layer="51"/>
<wire x1="-3.345" y1="-0.75" x2="-3.345" y2="-1.25" width="0" layer="20"/>
<wire x1="-3.345" y1="-1.25" x2="-3.345" y2="-2.75" width="0" layer="20"/>
<wire x1="3.345" y1="0" x2="3.345" y2="-0.75" width="0" layer="51"/>
<wire x1="3.345" y1="-0.75" x2="3.345" y2="-1.25" width="0" layer="20"/>
<wire x1="3.345" y1="-1.25" x2="3.345" y2="-2.75" width="0" layer="20"/>
<wire x1="-3.045" y1="0" x2="-3.345" y2="-0.75" width="0" layer="20"/>
<wire x1="3.045" y1="0" x2="3.345" y2="-0.75" width="0" layer="20"/>
<wire x1="3.345" y1="-2.75" x2="3.345" y2="-4.45" width="0" layer="20"/>
<wire x1="-3.345" y1="-2.75" x2="-3.345" y2="-4.45" width="0" layer="20"/>
<smd name="A11" x="-2.25" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A10" x="-1.75" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A8" x="-0.75" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A7" x="-0.25" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A6" x="0.25" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A5" x="0.75" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A3" x="1.75" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A2" x="2.25" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A12" x="-2.75" y="-2.45" dx="4" dy="0.25" layer="1" rot="R90"/>
<smd name="A9" x="-1.25" y="-2.45" dx="4" dy="0.25" layer="1" rot="R90"/>
<smd name="A4" x="1.25" y="-2.45" dx="4" dy="0.25" layer="1" rot="R90"/>
<smd name="A1" x="2.75" y="-2.45" dx="4" dy="0.25" layer="1" rot="R90"/>
<smd name="B1" x="-2.75" y="-2.45" dx="4" dy="0.25" layer="16" rot="R90"/>
<smd name="B4" x="-1.25" y="-2.45" dx="4" dy="0.25" layer="16" rot="R90"/>
<smd name="B9" x="1.25" y="-2.45" dx="4" dy="0.25" layer="16" rot="R90"/>
<smd name="B12" x="2.75" y="-2.45" dx="4" dy="0.25" layer="16" rot="R90"/>
<smd name="B2" x="-2.25" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B3" x="-1.75" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B5" x="-0.75" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B6" x="-0.25" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B7" x="0.25" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B8" x="0.75" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B10" x="1.75" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B11" x="2.25" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<wire x1="-8" y1="0" x2="-6.085" y2="0" width="0" layer="20"/>
<wire x1="-6.085" y1="0" x2="-5.885" y2="-0.2" width="0" layer="20" curve="-90"/>
<wire x1="-5.885" y1="-0.2" x2="-5.885" y2="-4.45" width="0" layer="20"/>
<wire x1="8" y1="0" x2="6.085" y2="0" width="0" layer="20"/>
<wire x1="6.085" y1="0" x2="5.885" y2="-0.2" width="0" layer="20" curve="90"/>
<wire x1="5.885" y1="-0.2" x2="5.885" y2="-4.45" width="0" layer="20"/>
<wire x1="-5.885" y1="-4.45" x2="-3.345" y2="-4.45" width="0" layer="20" curve="180"/>
<wire x1="3.345" y1="-4.45" x2="5.885" y2="-4.45" width="0" layer="20" curve="180"/>
</package>
<package name="USB_TYPE_C_DS_5">
<wire x1="-3.045" y1="0" x2="-3.145" y2="0" width="0" layer="20"/>
<wire x1="-3.145" y1="0" x2="-3.345" y2="-0.2" width="0" layer="20" curve="90"/>
<wire x1="-3.345" y1="-0.2" x2="-3.345" y2="-0.75" width="0" layer="20"/>
<wire x1="-3.045" y1="0" x2="3.045" y2="0" width="0" layer="20"/>
<wire x1="3.045" y1="0" x2="3.145" y2="0" width="0" layer="20"/>
<wire x1="3.145" y1="0" x2="3.345" y2="-0.2" width="0" layer="20" curve="-90"/>
<wire x1="3.345" y1="-0.2" x2="3.345" y2="-1.25" width="0" layer="20"/>
<wire x1="-3.345" y1="-0.75" x2="-3.345" y2="-1.25" width="0" layer="20"/>
<wire x1="-3.345" y1="-1.25" x2="-3.345" y2="-2.75" width="0" layer="20"/>
<wire x1="3.345" y1="-1.25" x2="3.345" y2="-2.75" width="0" layer="20"/>
<wire x1="3.345" y1="-2.75" x2="3.345" y2="-4.45" width="0" layer="20"/>
<wire x1="-3.345" y1="-2.75" x2="-3.345" y2="-4.45" width="0" layer="20"/>
<smd name="A11" x="-2.25" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A10" x="-1.75" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A8" x="-0.75" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A7" x="-0.25" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A6" x="0.25" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A5" x="0.75" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A3" x="1.75" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A2" x="2.25" y="-2.7" dx="3.5" dy="0.25" layer="1" rot="R90"/>
<smd name="A12" x="-2.75" y="-2.45" dx="4" dy="0.25" layer="1" rot="R90"/>
<smd name="A9" x="-1.25" y="-2.45" dx="4" dy="0.25" layer="1" rot="R90"/>
<smd name="A4" x="1.25" y="-2.45" dx="4" dy="0.25" layer="1" rot="R90"/>
<smd name="A1" x="2.75" y="-2.45" dx="4" dy="0.25" layer="1" rot="R90"/>
<smd name="B1" x="-2.75" y="-2.45" dx="4" dy="0.25" layer="16" rot="R90"/>
<smd name="B4" x="-1.25" y="-2.45" dx="4" dy="0.25" layer="16" rot="R90"/>
<smd name="B9" x="1.25" y="-2.45" dx="4" dy="0.25" layer="16" rot="R90"/>
<smd name="B12" x="2.75" y="-2.45" dx="4" dy="0.25" layer="16" rot="R90"/>
<smd name="B2" x="-2.25" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B3" x="-1.75" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B5" x="-0.75" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B6" x="-0.25" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B7" x="0.25" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B8" x="0.75" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B10" x="1.75" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<smd name="B11" x="2.25" y="-2.7" dx="3.5" dy="0.25" layer="16" rot="R90"/>
<wire x1="-8" y1="0" x2="-6.085" y2="0" width="0" layer="20"/>
<wire x1="-6.085" y1="0" x2="-5.885" y2="-0.2" width="0" layer="20" curve="-90"/>
<wire x1="-5.885" y1="-0.2" x2="-5.885" y2="-4.45" width="0" layer="20"/>
<wire x1="8" y1="0" x2="6.085" y2="0" width="0" layer="20"/>
<wire x1="6.085" y1="0" x2="5.885" y2="-0.2" width="0" layer="20" curve="90"/>
<wire x1="5.885" y1="-0.2" x2="5.885" y2="-4.45" width="0" layer="20"/>
<wire x1="-5.885" y1="-4.45" x2="-3.345" y2="-4.45" width="0" layer="20" curve="180"/>
<wire x1="3.345" y1="-4.45" x2="5.885" y2="-4.45" width="0" layer="20" curve="180"/>
</package>
</packages>
<symbols>
<symbol name="PCB_USB_C">
<pin name="A1" x="-15.24" y="22.86" visible="off" length="middle"/>
<pin name="A2" x="-15.24" y="20.32" visible="off" length="middle"/>
<pin name="A3" x="-15.24" y="17.78" visible="off" length="middle"/>
<pin name="A4" x="-15.24" y="15.24" visible="off" length="middle"/>
<wire x1="-10.16" y1="25.4" x2="7.62" y2="25.4" width="0.254" layer="94"/>
<pin name="A5" x="-15.24" y="12.7" visible="off" length="middle"/>
<wire x1="-10.16" y1="25.4" x2="-10.16" y2="-7.62" width="0.254" layer="94"/>
<wire x1="-10.16" y1="-7.62" x2="7.62" y2="-7.62" width="0.254" layer="94"/>
<wire x1="7.62" y1="-7.62" x2="7.62" y2="25.4" width="0.254" layer="94"/>
<text x="-9.398" y="26.162" size="1.27" layer="94">&gt;NAME</text>
<text x="-0.762" y="3.81" size="1.27" layer="94" rot="R90">PCB USB C </text>
<text x="-8.89" y="-5.588" size="1.27" layer="94" distance="100">GND 
TX1+
TX1-
VBUS
CC1
D+
D-
SBU1
VBUS
RX2-
RX2+
GND</text>
<pin name="A6" x="-15.24" y="10.16" visible="off" length="middle"/>
<pin name="A7" x="-15.24" y="7.62" visible="off" length="middle"/>
<pin name="A8" x="-15.24" y="5.08" visible="off" length="middle"/>
<pin name="A9" x="-15.24" y="2.54" visible="off" length="middle"/>
<pin name="A10" x="-15.24" y="0" visible="off" length="middle"/>
<pin name="A11" x="-15.24" y="-2.54" visible="off" length="middle"/>
<pin name="A12" x="-15.24" y="-5.08" visible="off" length="middle"/>
<pin name="B1" x="12.7" y="-5.08" visible="off" length="middle" rot="R180"/>
<pin name="B2" x="12.7" y="-2.54" visible="off" length="middle" rot="R180"/>
<pin name="B3" x="12.7" y="0" visible="off" length="middle" rot="R180"/>
<pin name="B4" x="12.7" y="2.54" visible="off" length="middle" rot="R180"/>
<pin name="B5" x="12.7" y="5.08" visible="off" length="middle" rot="R180"/>
<pin name="B6" x="12.7" y="7.62" visible="off" length="middle" rot="R180"/>
<pin name="B7" x="12.7" y="10.16" visible="off" length="middle" rot="R180"/>
<pin name="B8" x="12.7" y="12.7" visible="off" length="middle" rot="R180"/>
<pin name="B9" x="12.7" y="15.24" visible="off" length="middle" rot="R180"/>
<pin name="B10" x="12.7" y="17.78" visible="off" length="middle" rot="R180"/>
<pin name="B11" x="12.7" y="20.32" visible="off" length="middle" rot="R180"/>
<pin name="B12" x="12.7" y="22.86" visible="off" length="middle" rot="R180"/>
<text x="6.35" y="-5.588" size="1.27" layer="94" distance="100" align="bottom-right">GND 
RX1+
RX1-
VBUS
SBU2
D-
D+
CC2
VBUS
TX2-
TX2+
GND</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="PCB_USB_C">
<gates>
<gate name="G$1" symbol="PCB_USB_C" x="2.54" y="-7.62"/>
</gates>
<devices>
<device name="DS_1" package="USB_TYPE_C_DS_1">
<connects>
<connect gate="G$1" pin="A1" pad="A1"/>
<connect gate="G$1" pin="A10" pad="A10"/>
<connect gate="G$1" pin="A11" pad="A11"/>
<connect gate="G$1" pin="A12" pad="A12"/>
<connect gate="G$1" pin="A2" pad="A2"/>
<connect gate="G$1" pin="A3" pad="A3"/>
<connect gate="G$1" pin="A4" pad="A4"/>
<connect gate="G$1" pin="A5" pad="A5"/>
<connect gate="G$1" pin="A6" pad="A6"/>
<connect gate="G$1" pin="A7" pad="A7"/>
<connect gate="G$1" pin="A8" pad="A8"/>
<connect gate="G$1" pin="A9" pad="A9"/>
<connect gate="G$1" pin="B1" pad="B1"/>
<connect gate="G$1" pin="B10" pad="B10"/>
<connect gate="G$1" pin="B11" pad="B11"/>
<connect gate="G$1" pin="B12" pad="B12"/>
<connect gate="G$1" pin="B2" pad="B2"/>
<connect gate="G$1" pin="B3" pad="B3"/>
<connect gate="G$1" pin="B4" pad="B4"/>
<connect gate="G$1" pin="B5" pad="B5"/>
<connect gate="G$1" pin="B6" pad="B6"/>
<connect gate="G$1" pin="B7" pad="B7"/>
<connect gate="G$1" pin="B8" pad="B8"/>
<connect gate="G$1" pin="B9" pad="B9"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="DS_2" package="USB_TYPE_C_DS_2">
<connects>
<connect gate="G$1" pin="A1" pad="A1"/>
<connect gate="G$1" pin="A10" pad="A10"/>
<connect gate="G$1" pin="A11" pad="A11"/>
<connect gate="G$1" pin="A12" pad="A12"/>
<connect gate="G$1" pin="A2" pad="A2"/>
<connect gate="G$1" pin="A3" pad="A3"/>
<connect gate="G$1" pin="A4" pad="A4"/>
<connect gate="G$1" pin="A5" pad="A5"/>
<connect gate="G$1" pin="A6" pad="A6"/>
<connect gate="G$1" pin="A7" pad="A7"/>
<connect gate="G$1" pin="A8" pad="A8"/>
<connect gate="G$1" pin="A9" pad="A9"/>
<connect gate="G$1" pin="B1" pad="B1"/>
<connect gate="G$1" pin="B10" pad="B10"/>
<connect gate="G$1" pin="B11" pad="B11"/>
<connect gate="G$1" pin="B12" pad="B12"/>
<connect gate="G$1" pin="B2" pad="B2"/>
<connect gate="G$1" pin="B3" pad="B3"/>
<connect gate="G$1" pin="B4" pad="B4"/>
<connect gate="G$1" pin="B5" pad="B5"/>
<connect gate="G$1" pin="B6" pad="B6"/>
<connect gate="G$1" pin="B7" pad="B7"/>
<connect gate="G$1" pin="B8" pad="B8"/>
<connect gate="G$1" pin="B9" pad="B9"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="DS_3" package="USB_TYPE_C_DS_3">
<connects>
<connect gate="G$1" pin="A1" pad="A1"/>
<connect gate="G$1" pin="A10" pad="A10"/>
<connect gate="G$1" pin="A11" pad="A11"/>
<connect gate="G$1" pin="A12" pad="A12"/>
<connect gate="G$1" pin="A2" pad="A2"/>
<connect gate="G$1" pin="A3" pad="A3"/>
<connect gate="G$1" pin="A4" pad="A4"/>
<connect gate="G$1" pin="A5" pad="A5"/>
<connect gate="G$1" pin="A6" pad="A6"/>
<connect gate="G$1" pin="A7" pad="A7"/>
<connect gate="G$1" pin="A8" pad="A8"/>
<connect gate="G$1" pin="A9" pad="A9"/>
<connect gate="G$1" pin="B1" pad="B1"/>
<connect gate="G$1" pin="B10" pad="B10"/>
<connect gate="G$1" pin="B11" pad="B11"/>
<connect gate="G$1" pin="B12" pad="B12"/>
<connect gate="G$1" pin="B2" pad="B2"/>
<connect gate="G$1" pin="B3" pad="B3"/>
<connect gate="G$1" pin="B4" pad="B4"/>
<connect gate="G$1" pin="B5" pad="B5"/>
<connect gate="G$1" pin="B6" pad="B6"/>
<connect gate="G$1" pin="B7" pad="B7"/>
<connect gate="G$1" pin="B8" pad="B8"/>
<connect gate="G$1" pin="B9" pad="B9"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="DS_4" package="USB_TYPE_C_DS_4">
<connects>
<connect gate="G$1" pin="A1" pad="A1"/>
<connect gate="G$1" pin="A10" pad="A10"/>
<connect gate="G$1" pin="A11" pad="A11"/>
<connect gate="G$1" pin="A12" pad="A12"/>
<connect gate="G$1" pin="A2" pad="A2"/>
<connect gate="G$1" pin="A3" pad="A3"/>
<connect gate="G$1" pin="A4" pad="A4"/>
<connect gate="G$1" pin="A5" pad="A5"/>
<connect gate="G$1" pin="A6" pad="A6"/>
<connect gate="G$1" pin="A7" pad="A7"/>
<connect gate="G$1" pin="A8" pad="A8"/>
<connect gate="G$1" pin="A9" pad="A9"/>
<connect gate="G$1" pin="B1" pad="B1"/>
<connect gate="G$1" pin="B10" pad="B10"/>
<connect gate="G$1" pin="B11" pad="B11"/>
<connect gate="G$1" pin="B12" pad="B12"/>
<connect gate="G$1" pin="B2" pad="B2"/>
<connect gate="G$1" pin="B3" pad="B3"/>
<connect gate="G$1" pin="B4" pad="B4"/>
<connect gate="G$1" pin="B5" pad="B5"/>
<connect gate="G$1" pin="B6" pad="B6"/>
<connect gate="G$1" pin="B7" pad="B7"/>
<connect gate="G$1" pin="B8" pad="B8"/>
<connect gate="G$1" pin="B9" pad="B9"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="DS_5" package="USB_TYPE_C_DS_5">
<connects>
<connect gate="G$1" pin="A1" pad="A1"/>
<connect gate="G$1" pin="A10" pad="A10"/>
<connect gate="G$1" pin="A11" pad="A11"/>
<connect gate="G$1" pin="A12" pad="A12"/>
<connect gate="G$1" pin="A2" pad="A2"/>
<connect gate="G$1" pin="A3" pad="A3"/>
<connect gate="G$1" pin="A4" pad="A4"/>
<connect gate="G$1" pin="A5" pad="A5"/>
<connect gate="G$1" pin="A6" pad="A6"/>
<connect gate="G$1" pin="A7" pad="A7"/>
<connect gate="G$1" pin="A8" pad="A8"/>
<connect gate="G$1" pin="A9" pad="A9"/>
<connect gate="G$1" pin="B1" pad="B1"/>
<connect gate="G$1" pin="B10" pad="B10"/>
<connect gate="G$1" pin="B11" pad="B11"/>
<connect gate="G$1" pin="B12" pad="B12"/>
<connect gate="G$1" pin="B2" pad="B2"/>
<connect gate="G$1" pin="B3" pad="B3"/>
<connect gate="G$1" pin="B4" pad="B4"/>
<connect gate="G$1" pin="B5" pad="B5"/>
<connect gate="G$1" pin="B6" pad="B6"/>
<connect gate="G$1" pin="B7" pad="B7"/>
<connect gate="G$1" pin="B8" pad="B8"/>
<connect gate="G$1" pin="B9" pad="B9"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U$1" library="USB_pcb_connectors" deviceset="PCB_USB_C" device="DS_5"/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="-33.02" y="38.1" smashed="yes">
<attribute name="NAME" x="-42.418" y="64.262" size="1.27" layer="94"/>
</instance>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="6.3" minversion="6.2.2" severity="warning">
Since Version 6.2.2 text objects can contain more than one line,
which will not be processed correctly with this version.
</note>
</compatibility>
</eagle>
