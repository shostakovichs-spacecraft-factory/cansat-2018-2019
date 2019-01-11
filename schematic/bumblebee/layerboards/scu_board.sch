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
<layer number="1" name="Top" color="4" fill="1" visible="yes" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="yes" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="yes" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="yes" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="yes" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="yes" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="yes" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="yes" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="yes" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="yes" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="yes" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="yes" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="yes" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="yes" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="yes" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="yes" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="yes" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="yes" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="yes" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="yes" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="yes" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="yes" active="no"/>
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
<library name="bluepill">
<packages>
<package name="SCU">
<rectangle x1="-17.5" y1="-30.5" x2="17.5" y2="30.5" layer="21"/>
<pad name="P$1" x="1.27" y="-27.5" drill="0.8" shape="square"/>
<pad name="SW-CLK" x="1.27" y="-25" drill="0.8" shape="square"/>
<pad name="P$3" x="-1.27" y="-25" drill="0.8" shape="square"/>
<pad name="P$4" x="-3.81" y="-25" drill="0.8" shape="square"/>
<pad name="P$5" x="-6.35" y="-25" drill="0.8" shape="square"/>
<pad name="P$6" x="-8.89" y="-25" drill="0.8" shape="square"/>
<pad name="P$7" x="-11.43" y="-25" drill="0.8" shape="square"/>
<pad name="P$8" x="-11.43" y="-27.5" drill="0.8" shape="square"/>
<pad name="P$9" x="-8.89" y="-27.5" drill="0.8" shape="square"/>
<pad name="P$10" x="-6.35" y="-27.5" drill="0.8" shape="square"/>
<pad name="P$11" x="-3.81" y="-27.5" drill="0.8" shape="square"/>
<pad name="P$12" x="-1.27" y="-27.5" drill="0.8" shape="square"/>
<pad name="SW-DAT" x="3.81" y="-25" drill="0.8" shape="square"/>
<pad name="P$14" x="6.35" y="-25" drill="0.8" shape="square"/>
<pad name="P$15" x="8.89" y="-25" drill="0.8" shape="square"/>
<pad name="VDD" x="11.43" y="-25" drill="0.8" shape="square"/>
<pad name="P$17" x="3.81" y="-27.5" drill="0.8" shape="square"/>
<pad name="P$18" x="6.35" y="-27.5" drill="0.8" shape="square"/>
<pad name="GND_0" x="8.89" y="-27.5" drill="0.8" shape="square"/>
<pad name="P$20" x="11.43" y="-27.5" drill="0.8" shape="square"/>
<pad name="PB5" x="14.5" y="1.27" drill="0.8" shape="square"/>
<pad name="PC12" x="14.5" y="3.81" drill="0.8" shape="square"/>
<pad name="PC10" x="14.5" y="6.35" drill="0.8" shape="square"/>
<pad name="GND_3" x="14.5" y="8.89" drill="0.8" shape="square"/>
<pad name="PA9" x="14.5" y="11.43" drill="0.8" shape="square"/>
<pad name="PA8" x="14.5" y="13.97" drill="0.8" shape="square"/>
<pad name="PA6" x="14.5" y="-1.27" drill="0.8" shape="square"/>
<pad name="PB8" x="14.5" y="-3.81" drill="0.8" shape="square"/>
<pad name="PA5" x="14.5" y="-6.35" drill="0.8" shape="square"/>
<pad name="PC1" x="14.5" y="-8.89" drill="0.8" shape="square"/>
<pad name="PA7" x="14.5" y="-11.43" drill="0.8" shape="square"/>
<pad name="PC13" x="14.5" y="-13.97" drill="0.8" shape="square"/>
<pad name="PB1" x="14.5" y="-16.51" drill="0.8" shape="square"/>
<pad name="PA11" x="12" y="13.97" drill="0.8" shape="square"/>
<pad name="PA12" x="12" y="11.43" drill="0.8" shape="square"/>
<pad name="+3.3V" x="12" y="8.89" drill="0.8" shape="square"/>
<pad name="PA10" x="12" y="6.35" drill="0.8" shape="square"/>
<pad name="PC11" x="12" y="3.81" drill="0.8" shape="square"/>
<pad name="PD2" x="12" y="1.27" drill="0.8" shape="square"/>
<pad name="PB6" x="12" y="-1.27" drill="0.8" shape="square"/>
<pad name="PB7" x="12" y="-3.81" drill="0.8" shape="square"/>
<pad name="PB9" x="12" y="-6.35" drill="0.8" shape="square"/>
<pad name="PC0" x="12" y="-8.89" drill="0.8" shape="square"/>
<pad name="PB0" x="12" y="-11.43" drill="0.8" shape="square"/>
<pad name="VBAT" x="12" y="-13.97" drill="0.8" shape="square"/>
<pad name="NRST" x="12" y="-16.51" drill="0.8" shape="square"/>
<pad name="PB11" x="-12" y="1.27" drill="0.8" shape="square" first="yes"/>
<pad name="PB12" x="-12" y="3.81" drill="0.8" shape="square"/>
<pad name="PB15" x="-12" y="6.35" drill="0.8" shape="square"/>
<pad name="PC7" x="-12" y="8.89" drill="0.8" shape="square"/>
<pad name="5VUSB" x="-12" y="11.43" drill="0.8" shape="square"/>
<pad name="GND_1" x="-12" y="13.97" drill="0.8" shape="square"/>
<pad name="VIN" x="-14.5" y="13.97" drill="0.8" shape="square"/>
<pad name="PC9" x="-14.5" y="11.43" drill="0.8" shape="square"/>
<pad name="PC8" x="-14.5" y="8.89" drill="0.8" shape="square"/>
<pad name="PC6" x="-14.5" y="6.35" drill="0.8" shape="square"/>
<pad name="PB14" x="-14.5" y="3.81" drill="0.8" shape="square"/>
<pad name="PB13" x="-14.5" y="1.27" drill="0.8" shape="square"/>
<pad name="PB10" x="-14.5" y="-1.27" drill="0.8" shape="square"/>
<pad name="PC4" x="-14.5" y="-3.81" drill="0.8" shape="square"/>
<pad name="PA3" x="-14.5" y="-6.35" drill="0.8" shape="square"/>
<pad name="PA1" x="-14.5" y="-8.89" drill="0.8" shape="square"/>
<pad name="GND_2" x="-14.5" y="-11.43" drill="0.8" shape="square"/>
<pad name="PA0" x="-14.5" y="-13.97" drill="0.8" shape="square"/>
<pad name="PC2" x="-14.5" y="-16.51" drill="0.8" shape="square"/>
<pad name="VDDA" x="-12" y="-16.51" drill="0.8" shape="square"/>
<pad name="GNDA" x="-12" y="-13.97" drill="0.8" shape="square"/>
<pad name="3.3V" x="-12" y="-11.43" drill="0.8" shape="square"/>
<pad name="PA2" x="-12" y="-8.89" drill="0.8" shape="square"/>
<pad name="PC3" x="-12" y="-6.35" drill="0.8" shape="square"/>
<pad name="PA4" x="-12" y="-3.81" drill="0.8" shape="square"/>
<pad name="PC5" x="-12" y="-1.27" drill="0.8" shape="square"/>
<text x="-15.4" y="33.4" size="1.27" layer="25">&gt;NAME</text>
<text x="-15" y="-13.5" size="1.27" layer="21">&gt;NAME</text>
<text x="-14.7" y="-34.3" size="1.27" layer="27">&gt;VALUE</text>
</package>
<package name="BME">
<rectangle x1="-5.75" y1="-7.5" x2="5.75" y2="7.5" layer="21"/>
<hole x="-3.25" y="5" drill="3"/>
<hole x="-3.25" y="-5" drill="3"/>
<pad name="UCC" x="4.25" y="6.35" drill="0.8" shape="square"/>
<pad name="SD0" x="4.25" y="-6.35" drill="0.8" shape="square"/>
<pad name="SDA" x="4.25" y="-1.27" drill="0.8" shape="square"/>
<pad name="SCL" x="4.25" y="1.27" drill="0.8" shape="square"/>
<pad name="GND" x="4.25" y="3.81" drill="0.8" shape="square"/>
<pad name="CSB" x="4.25" y="-3.81" drill="0.8" shape="square"/>
<text x="-5.19" y="8.84" size="1.27" layer="25">&gt;NAME</text>
<text x="-5.19" y="-9.8" size="1.27" layer="27">&gt;VALUE</text>
</package>
<package name="LSM6DS3">
<description>lsm</description>
<rectangle x1="-6.5" y1="-9" x2="6.5" y2="9" layer="21"/>
<hole x="2.5" y="7" drill="3"/>
<hole x="2.5" y="-7" drill="3"/>
<pad name="INT1" x="5" y="0" drill="0.8" shape="square"/>
<pad name="SCX" x="5" y="-2.54" drill="0.8" shape="square"/>
<pad name="INT2" x="5" y="2.54" drill="0.8" shape="square"/>
<pad name="OCS" x="5" y="5.08" drill="0.8" shape="square"/>
<pad name="SDX" x="5" y="-5.08" drill="0.8" shape="square"/>
<pad name="SCL" x="-5" y="0" drill="0.8" shape="square"/>
<pad name="GND" x="-5" y="2.54" drill="0.8" shape="square"/>
<pad name="3V3" x="-5" y="5.08" drill="0.8" shape="square"/>
<pad name="VIN" x="-5" y="7.62" drill="0.8" shape="square"/>
<pad name="SDA" x="-5" y="-2.54" drill="0.8" shape="square"/>
<pad name="CS" x="-5" y="-5.08" drill="0.8" shape="square"/>
<pad name="SAD" x="-5" y="-7.62" drill="0.8" shape="square"/>
<text x="-5.08" y="10.16" size="1.27" layer="25">&gt;NAME</text>
<text x="-5.08" y="-11.43" size="1.27" layer="27">&gt;VALUE</text>
<dimension x1="3.122521875" y1="-5.635278125" x2="1.877478125" y2="-8.364721875" x3="17.77999375" y3="-13.9700125" textsize="1.27" layer="21" dtype="diameter"/>
<dimension x1="-6.5" y1="-9" x2="6.5" y2="-9" x3="0" y3="-16.51" textsize="1.27" layer="21"/>
</package>
<package name="ADS">
<rectangle x1="-4.5" y1="-13" x2="4.5" y2="13" layer="21"/>
<pad name="ALERT" x="-3.5" y="-1.27" drill="0.8" shape="square"/>
<pad name="ADDR" x="-3.5" y="1.27" drill="0.8" shape="square"/>
<pad name="SDA" x="-3.5" y="3.81" drill="0.8" shape="square"/>
<pad name="SCL" x="-3.5" y="6.35" drill="0.8" shape="square"/>
<pad name="G" x="-3.5" y="8.89" drill="0.8" shape="square"/>
<pad name="V" x="-3.5" y="11.43" drill="0.8" shape="square"/>
<pad name="A0" x="-3.5" y="-3.81" drill="0.8" shape="square"/>
<pad name="A1" x="-3.5" y="-6.35" drill="0.8" shape="square"/>
<pad name="A2" x="-3.5" y="-8.89" drill="0.8" shape="square"/>
<pad name="A3" x="-3.5" y="-11.43" drill="0.8" shape="square"/>
<hole x="1.5" y="10" drill="3"/>
<hole x="1.5" y="-10" drill="3"/>
<text x="-3.81" y="15.24" size="1.27" layer="25">&gt;NAME</text>
<text x="-3.81" y="-16.51" size="1.27" layer="27">&gt;VALUE</text>
</package>
</packages>
<symbols>
<symbol name="SCU">
<pin name="PB7" x="10.16" y="68.58" length="middle" rot="R180"/>
<pin name="PB6" x="10.16" y="73.66" length="middle" rot="R180"/>
<pin name="PD2" x="10.16" y="78.74" length="middle" rot="R180"/>
<pin name="PC11" x="10.16" y="83.82" length="middle" rot="R180"/>
<pin name="PA10" x="10.16" y="88.9" length="middle" rot="R180"/>
<pin name="+3.3V" x="10.16" y="93.98" length="middle" rot="R180"/>
<pin name="PA12" x="10.16" y="99.06" length="middle" rot="R180"/>
<pin name="PA11" x="10.16" y="104.14" length="middle" rot="R180"/>
<pin name="PB9" x="10.16" y="63.5" length="middle" rot="R180"/>
<pin name="PC0" x="10.16" y="58.42" length="middle" rot="R180"/>
<pin name="PB0" x="10.16" y="53.34" length="middle" rot="R180"/>
<pin name="VBAT" x="10.16" y="48.26" length="middle" rot="R180"/>
<pin name="NRST" x="10.16" y="43.18" length="middle" rot="R180"/>
<pin name="PB11" x="-20.32" y="78.74" length="middle"/>
<pin name="PC5" x="-20.32" y="73.66" length="middle"/>
<pin name="PA4" x="-20.32" y="68.58" length="middle"/>
<pin name="PC3" x="-20.32" y="63.5" length="middle"/>
<pin name="PA2" x="-20.32" y="58.42" length="middle"/>
<pin name="3.3V" x="-20.32" y="53.34" length="middle"/>
<pin name="GNDA" x="-20.32" y="48.26" length="middle"/>
<pin name="VDDA" x="-20.32" y="43.18" length="middle"/>
<pin name="PB12" x="-20.32" y="83.82" length="middle"/>
<pin name="PB15" x="-20.32" y="88.9" length="middle"/>
<pin name="PC7" x="-20.32" y="93.98" length="middle"/>
<pin name="5VUSB" x="-20.32" y="99.06" length="middle"/>
<pin name="GND_1" x="-20.32" y="104.14" length="middle"/>
<pin name="PC4" x="-35.56" y="2.54" length="middle"/>
<pin name="PB10" x="-35.56" y="7.62" length="middle"/>
<pin name="PB13" x="-35.56" y="12.7" length="middle"/>
<pin name="PB14" x="-35.56" y="17.78" length="middle"/>
<pin name="PC6" x="-35.56" y="22.86" length="middle"/>
<pin name="PC8" x="-35.56" y="27.94" length="middle"/>
<pin name="PC9" x="-35.56" y="33.02" length="middle"/>
<pin name="VIN" x="-35.56" y="38.1" length="middle"/>
<pin name="PA3" x="-35.56" y="-2.54" length="middle"/>
<pin name="PA1" x="-35.56" y="-7.62" length="middle"/>
<pin name="GND_2" x="-35.56" y="-12.7" length="middle"/>
<pin name="PA0" x="-35.56" y="-17.78" length="middle"/>
<pin name="PC2" x="-35.56" y="-22.86" length="middle"/>
<pin name="PB5" x="25.4" y="12.7" length="middle" rot="R180"/>
<pin name="PA6" x="25.4" y="7.62" length="middle" rot="R180"/>
<pin name="PB8" x="25.4" y="2.54" length="middle" rot="R180"/>
<pin name="PA5" x="25.4" y="-2.54" length="middle" rot="R180"/>
<pin name="PC1" x="25.4" y="-7.62" length="middle" rot="R180"/>
<pin name="PA7" x="25.4" y="-12.7" length="middle" rot="R180"/>
<pin name="PC13" x="25.4" y="-17.78" length="middle" rot="R180"/>
<pin name="PB1" x="25.4" y="-22.86" length="middle" rot="R180"/>
<pin name="PC12" x="25.4" y="17.78" length="middle" rot="R180"/>
<pin name="PC10" x="25.4" y="22.86" length="middle" rot="R180"/>
<pin name="GND_3" x="25.4" y="27.94" length="middle" rot="R180"/>
<pin name="PA9" x="25.4" y="33.02" length="middle" rot="R180"/>
<pin name="PA8" x="25.4" y="38.1" length="middle" rot="R180"/>
<pin name="SW-CLK" x="-2.54" y="-40.64" length="middle" rot="R270"/>
<pin name="SW-DAT" x="2.54" y="-40.64" length="middle" rot="R270"/>
<pin name="P$55" x="7.62" y="-40.64" length="middle" rot="R270"/>
<pin name="P$56" x="12.7" y="-40.64" length="middle" rot="R270"/>
<pin name="VDD" x="17.78" y="-40.64" length="middle" rot="R270"/>
<pin name="P$58" x="-7.62" y="-40.64" length="middle" rot="R270"/>
<pin name="P$59" x="-12.7" y="-40.64" length="middle" rot="R270"/>
<pin name="P$60" x="-17.78" y="-40.64" length="middle" rot="R270"/>
<pin name="P$61" x="-22.86" y="-40.64" length="middle" rot="R270"/>
<pin name="P$62" x="-27.94" y="-40.64" length="middle" rot="R270"/>
<wire x1="5.08" y1="106.68" x2="5.08" y2="-25.4" width="0.254" layer="94"/>
<wire x1="-15.24" y1="-25.4" x2="-15.24" y2="106.68" width="0.254" layer="94"/>
<wire x1="-30.48" y1="40.64" x2="-30.48" y2="-25.4" width="0.254" layer="94"/>
<wire x1="-30.48" y1="-25.4" x2="-15.24" y2="-25.4" width="0.254" layer="94"/>
<wire x1="5.08" y1="-25.4" x2="20.32" y2="-25.4" width="0.254" layer="94"/>
<wire x1="20.32" y1="-25.4" x2="20.32" y2="40.64" width="0.254" layer="94"/>
<wire x1="-30.48" y1="-45.72" x2="-15.24" y2="-45.72" width="0.254" layer="94"/>
<wire x1="5.08" y1="-45.72" x2="20.32" y2="-45.72" width="0.254" layer="94"/>
<wire x1="20.32" y1="-45.72" x2="20.32" y2="-63.5" width="0.254" layer="94"/>
<wire x1="-30.48" y1="-63.5" x2="-30.48" y2="-45.72" width="0.254" layer="94"/>
<wire x1="-15.24" y1="-25.4" x2="-15.24" y2="-45.72" width="0.254" layer="94"/>
<wire x1="-15.24" y1="-45.72" x2="5.08" y2="-45.72" width="0.254" layer="94"/>
<wire x1="5.08" y1="-45.72" x2="5.08" y2="-25.4" width="0.254" layer="94"/>
<pin name="P$1" x="-27.94" y="-68.58" length="middle" rot="R90"/>
<pin name="P$2" x="-22.86" y="-68.58" length="middle" rot="R90"/>
<pin name="P$3" x="-17.78" y="-68.58" length="middle" rot="R90"/>
<pin name="P$4" x="-12.7" y="-68.58" length="middle" rot="R90"/>
<pin name="P$5" x="-7.62" y="-68.58" length="middle" rot="R90"/>
<pin name="P$6" x="-2.54" y="-68.58" length="middle" rot="R90"/>
<pin name="P$7" x="2.54" y="-68.58" length="middle" rot="R90"/>
<pin name="P$8" x="7.62" y="-68.58" length="middle" rot="R90"/>
<pin name="GND_0" x="12.7" y="-68.58" length="middle" rot="R90"/>
<pin name="P$9" x="17.78" y="-68.58" length="middle" rot="R90"/>
<wire x1="-30.48" y1="-63.5" x2="20.32" y2="-63.5" width="0.254" layer="94"/>
<text x="-27.94" y="50.8" size="1.27" layer="95">&gt;NAME</text>
<text x="-27.94" y="-81.28" size="1.27" layer="96">&gt;VALUE</text>
</symbol>
<symbol name="BME">
<pin name="SCL" x="15.24" y="2.54" length="middle" rot="R180"/>
<pin name="SDA" x="15.24" y="-2.54" length="middle" rot="R180"/>
<pin name="CSB" x="15.24" y="-7.62" length="middle" rot="R180"/>
<pin name="SD0" x="15.24" y="-12.7" length="middle" rot="R180"/>
<pin name="GND" x="15.24" y="7.62" length="middle" rot="R180"/>
<pin name="VCC" x="15.24" y="12.7" length="middle" rot="R180"/>
<wire x1="10.16" y1="15.24" x2="-7.62" y2="15.24" width="0.254" layer="94"/>
<wire x1="-7.62" y1="15.24" x2="-7.62" y2="-15.24" width="0.254" layer="94"/>
<wire x1="-7.62" y1="-15.24" x2="10.16" y2="-15.24" width="0.254" layer="94"/>
<wire x1="10.16" y1="-15.24" x2="10.16" y2="15.24" width="0.254" layer="94"/>
<text x="-7.62" y="17.78" size="1.27" layer="95">&gt;NAME</text>
<text x="-7.62" y="-20.32" size="1.27" layer="96">&gt;VALUE</text>
</symbol>
<symbol name="LSM6DS3">
<description>lSM</description>
<pin name="OCS" x="15.24" y="10.16" length="middle" rot="R180"/>
<pin name="INT2" x="15.24" y="5.08" length="middle" rot="R180"/>
<pin name="INT1" x="15.24" y="0" length="middle" rot="R180"/>
<pin name="SCX" x="15.24" y="-5.08" length="middle" rot="R180"/>
<pin name="SDX" x="15.24" y="-10.16" length="middle" rot="R180"/>
<pin name="SCL" x="-12.7" y="0" length="middle"/>
<pin name="GND" x="-12.7" y="5.08" length="middle"/>
<pin name="3V3" x="-12.7" y="10.16" length="middle"/>
<pin name="VIN" x="-12.7" y="15.24" length="middle"/>
<pin name="SDA" x="-12.7" y="-5.08" length="middle"/>
<pin name="CS" x="-12.7" y="-10.16" length="middle"/>
<pin name="SAD" x="-12.7" y="-15.24" length="middle"/>
<wire x1="-7.62" y1="17.78" x2="10.16" y2="17.78" width="0.254" layer="94"/>
<wire x1="10.16" y1="17.78" x2="10.16" y2="-17.78" width="0.254" layer="94"/>
<wire x1="10.16" y1="-17.78" x2="-7.62" y2="-17.78" width="0.254" layer="94"/>
<wire x1="-7.62" y1="-17.78" x2="-7.62" y2="17.78" width="0.254" layer="94"/>
<text x="-7.62" y="20.32" size="1.27" layer="95">&gt;NAME</text>
<text x="-7.62" y="-22.86" size="1.27" layer="96">&gt;VALUE</text>
</symbol>
<symbol name="ADS">
<pin name="ADDR" x="-15.24" y="2.54" length="middle"/>
<pin name="SDA" x="-15.24" y="7.62" length="middle"/>
<pin name="SCL" x="-15.24" y="12.7" length="middle"/>
<pin name="G" x="-15.24" y="17.78" length="middle"/>
<pin name="V" x="-15.24" y="22.86" length="middle"/>
<pin name="ALERT" x="-15.24" y="-2.54" length="middle"/>
<pin name="A0" x="-15.24" y="-7.62" length="middle"/>
<pin name="A1" x="-15.24" y="-12.7" length="middle"/>
<pin name="A2" x="-15.24" y="-17.78" length="middle"/>
<pin name="A3" x="-15.24" y="-22.86" length="middle"/>
<wire x1="-10.16" y1="25.4" x2="10.16" y2="25.4" width="0.254" layer="94"/>
<wire x1="10.16" y1="25.4" x2="10.16" y2="-25.4" width="0.254" layer="94"/>
<wire x1="10.16" y1="-25.4" x2="-10.16" y2="-25.4" width="0.254" layer="94"/>
<wire x1="-10.16" y1="-25.4" x2="-10.16" y2="25.4" width="0.254" layer="94"/>
<text x="-7.62" y="27.94" size="1.27" layer="95">&gt;NAME</text>
<text x="-7.62" y="-30.48" size="1.27" layer="96">&gt;VALUE</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="SCU">
<gates>
<gate name="G$1" symbol="SCU" x="0" y="0"/>
</gates>
<devices>
<device name="" package="SCU">
<connects>
<connect gate="G$1" pin="+3.3V" pad="+3.3V"/>
<connect gate="G$1" pin="3.3V" pad="3.3V"/>
<connect gate="G$1" pin="5VUSB" pad="5VUSB"/>
<connect gate="G$1" pin="GNDA" pad="GNDA"/>
<connect gate="G$1" pin="GND_0" pad="GND_0"/>
<connect gate="G$1" pin="GND_1" pad="GND_1"/>
<connect gate="G$1" pin="GND_2" pad="GND_2"/>
<connect gate="G$1" pin="GND_3" pad="GND_3"/>
<connect gate="G$1" pin="NRST" pad="NRST"/>
<connect gate="G$1" pin="P$1" pad="P$8"/>
<connect gate="G$1" pin="P$2" pad="P$9"/>
<connect gate="G$1" pin="P$3" pad="P$10"/>
<connect gate="G$1" pin="P$4" pad="P$11"/>
<connect gate="G$1" pin="P$5" pad="P$12"/>
<connect gate="G$1" pin="P$55" pad="P$14"/>
<connect gate="G$1" pin="P$56" pad="P$15"/>
<connect gate="G$1" pin="P$58" pad="P$3"/>
<connect gate="G$1" pin="P$59" pad="P$4"/>
<connect gate="G$1" pin="P$6" pad="P$1"/>
<connect gate="G$1" pin="P$60" pad="P$5"/>
<connect gate="G$1" pin="P$61" pad="P$6"/>
<connect gate="G$1" pin="P$62" pad="P$7"/>
<connect gate="G$1" pin="P$7" pad="P$17"/>
<connect gate="G$1" pin="P$8" pad="P$18"/>
<connect gate="G$1" pin="P$9" pad="P$20"/>
<connect gate="G$1" pin="PA0" pad="PA0"/>
<connect gate="G$1" pin="PA1" pad="PA1"/>
<connect gate="G$1" pin="PA10" pad="PA10"/>
<connect gate="G$1" pin="PA11" pad="PA11"/>
<connect gate="G$1" pin="PA12" pad="PA12"/>
<connect gate="G$1" pin="PA2" pad="PA2"/>
<connect gate="G$1" pin="PA3" pad="PA3"/>
<connect gate="G$1" pin="PA4" pad="PA4"/>
<connect gate="G$1" pin="PA5" pad="PA5"/>
<connect gate="G$1" pin="PA6" pad="PA6"/>
<connect gate="G$1" pin="PA7" pad="PA7"/>
<connect gate="G$1" pin="PA8" pad="PA8"/>
<connect gate="G$1" pin="PA9" pad="PA9"/>
<connect gate="G$1" pin="PB0" pad="PB0"/>
<connect gate="G$1" pin="PB1" pad="PB1"/>
<connect gate="G$1" pin="PB10" pad="PB10"/>
<connect gate="G$1" pin="PB11" pad="PB11"/>
<connect gate="G$1" pin="PB12" pad="PB12"/>
<connect gate="G$1" pin="PB13" pad="PB13"/>
<connect gate="G$1" pin="PB14" pad="PB14"/>
<connect gate="G$1" pin="PB15" pad="PB15"/>
<connect gate="G$1" pin="PB5" pad="PB5"/>
<connect gate="G$1" pin="PB6" pad="PB6"/>
<connect gate="G$1" pin="PB7" pad="PB7"/>
<connect gate="G$1" pin="PB8" pad="PB8"/>
<connect gate="G$1" pin="PB9" pad="PB9"/>
<connect gate="G$1" pin="PC0" pad="PC0"/>
<connect gate="G$1" pin="PC1" pad="PC1"/>
<connect gate="G$1" pin="PC10" pad="PC10"/>
<connect gate="G$1" pin="PC11" pad="PC11"/>
<connect gate="G$1" pin="PC12" pad="PC12"/>
<connect gate="G$1" pin="PC13" pad="PC13"/>
<connect gate="G$1" pin="PC2" pad="PC2"/>
<connect gate="G$1" pin="PC3" pad="PC3"/>
<connect gate="G$1" pin="PC4" pad="PC4"/>
<connect gate="G$1" pin="PC5" pad="PC5"/>
<connect gate="G$1" pin="PC6" pad="PC6"/>
<connect gate="G$1" pin="PC7" pad="PC7"/>
<connect gate="G$1" pin="PC8" pad="PC8"/>
<connect gate="G$1" pin="PC9" pad="PC9"/>
<connect gate="G$1" pin="PD2" pad="PD2"/>
<connect gate="G$1" pin="SW-CLK" pad="SW-CLK"/>
<connect gate="G$1" pin="SW-DAT" pad="SW-DAT"/>
<connect gate="G$1" pin="VBAT" pad="VBAT"/>
<connect gate="G$1" pin="VDD" pad="VDD"/>
<connect gate="G$1" pin="VDDA" pad="VDDA"/>
<connect gate="G$1" pin="VIN" pad="VIN"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="BME">
<gates>
<gate name="G$1" symbol="BME" x="0" y="0"/>
</gates>
<devices>
<device name="" package="BME">
<connects>
<connect gate="G$1" pin="CSB" pad="CSB"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="SCL" pad="SCL"/>
<connect gate="G$1" pin="SD0" pad="SD0"/>
<connect gate="G$1" pin="SDA" pad="SDA"/>
<connect gate="G$1" pin="VCC" pad="UCC"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="LSM6DS3">
<description>lsm</description>
<gates>
<gate name="G$1" symbol="LSM6DS3" x="0" y="0"/>
</gates>
<devices>
<device name="" package="LSM6DS3">
<connects>
<connect gate="G$1" pin="3V3" pad="3V3"/>
<connect gate="G$1" pin="CS" pad="CS"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="INT1" pad="INT1"/>
<connect gate="G$1" pin="INT2" pad="INT2"/>
<connect gate="G$1" pin="OCS" pad="OCS"/>
<connect gate="G$1" pin="SAD" pad="SAD"/>
<connect gate="G$1" pin="SCL" pad="SCL"/>
<connect gate="G$1" pin="SCX" pad="SCX"/>
<connect gate="G$1" pin="SDA" pad="SDA"/>
<connect gate="G$1" pin="SDX" pad="SDX"/>
<connect gate="G$1" pin="VIN" pad="VIN"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="ADS">
<gates>
<gate name="G$1" symbol="ADS" x="0" y="0"/>
</gates>
<devices>
<device name="" package="ADS">
<connects>
<connect gate="G$1" pin="A0" pad="A0"/>
<connect gate="G$1" pin="A1" pad="A1"/>
<connect gate="G$1" pin="A2" pad="A2"/>
<connect gate="G$1" pin="A3" pad="A3"/>
<connect gate="G$1" pin="ADDR" pad="ADDR"/>
<connect gate="G$1" pin="ALERT" pad="ALERT"/>
<connect gate="G$1" pin="G" pad="G"/>
<connect gate="G$1" pin="SCL" pad="SCL"/>
<connect gate="G$1" pin="SDA" pad="SDA"/>
<connect gate="G$1" pin="V" pad="V"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply1" urn="urn:adsk.eagle:library:371">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
 GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
 Please keep in mind, that these devices are necessary for the
 automatic wiring of the supply signals.&lt;p&gt;
 The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
 In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
 &lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="GND" urn="urn:adsk.eagle:symbol:26925/1" library_version="1">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="GND" urn="urn:adsk.eagle:component:26954/1" prefix="GND" library_version="1">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="GND" x="0" y="0"/>
</gates>
<devices>
<device name="">
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
<part name="U$1" library="bluepill" deviceset="SCU" device=""/>
<part name="U$2" library="bluepill" deviceset="BME" device=""/>
<part name="GND1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND2" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="U$3" library="bluepill" deviceset="LSM6DS3" device=""/>
<part name="GND3" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND4" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="U$4" library="bluepill" deviceset="ADS" device=""/>
<part name="U$5" library="bluepill" deviceset="ADS" device=""/>
<part name="GND5" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND6" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="5.08" y="2.54" smashed="yes">
<attribute name="NAME" x="-22.86" y="53.34" size="1.27" layer="95"/>
<attribute name="VALUE" x="-22.86" y="-78.74" size="1.27" layer="96"/>
</instance>
<instance part="U$2" gate="G$1" x="78.74" y="48.26" smashed="yes" rot="R180">
<attribute name="NAME" x="86.36" y="30.48" size="1.27" layer="95" rot="R180"/>
<attribute name="VALUE" x="86.36" y="68.58" size="1.27" layer="96" rot="R180"/>
</instance>
<instance part="GND1" gate="1" x="55.88" y="35.56" smashed="yes">
<attribute name="VALUE" x="53.34" y="33.02" size="1.778" layer="96"/>
</instance>
<instance part="GND2" gate="1" x="-38.1" y="-15.24" smashed="yes">
<attribute name="VALUE" x="-40.64" y="-17.78" size="1.778" layer="96"/>
</instance>
<instance part="U$3" gate="G$1" x="76.2" y="-5.08" smashed="yes">
<attribute name="NAME" x="68.58" y="15.24" size="1.27" layer="95"/>
<attribute name="VALUE" x="68.58" y="-27.94" size="1.27" layer="96"/>
</instance>
<instance part="GND3" gate="1" x="58.42" y="0" smashed="yes">
<attribute name="VALUE" x="55.88" y="-2.54" size="1.778" layer="96"/>
</instance>
<instance part="GND4" gate="1" x="58.42" y="-17.78" smashed="yes">
<attribute name="VALUE" x="55.88" y="-20.32" size="1.778" layer="96"/>
</instance>
<instance part="U$4" gate="G$1" x="78.74" y="106.68" smashed="yes">
<attribute name="NAME" x="71.12" y="134.62" size="1.27" layer="95"/>
<attribute name="VALUE" x="71.12" y="76.2" size="1.27" layer="96"/>
</instance>
<instance part="U$5" gate="G$1" x="78.74" y="175.26" smashed="yes">
<attribute name="NAME" x="71.12" y="203.2" size="1.27" layer="95"/>
<attribute name="VALUE" x="71.12" y="144.78" size="1.27" layer="96"/>
</instance>
<instance part="GND5" gate="1" x="55.88" y="124.46" smashed="yes">
<attribute name="VALUE" x="53.34" y="121.92" size="1.778" layer="96"/>
</instance>
<instance part="GND6" gate="1" x="55.88" y="193.04" smashed="yes">
<attribute name="VALUE" x="53.34" y="190.5" size="1.778" layer="96"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="GND" class="0">
<segment>
<pinref part="GND1" gate="1" pin="GND"/>
<pinref part="U$2" gate="G$1" pin="GND"/>
<wire x1="55.88" y1="38.1" x2="55.88" y2="40.64" width="0.1524" layer="91"/>
<wire x1="55.88" y1="40.64" x2="63.5" y2="40.64" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND2" gate="1" pin="GND"/>
<pinref part="U$1" gate="G$1" pin="GND_2"/>
<wire x1="-38.1" y1="-12.7" x2="-38.1" y2="-10.16" width="0.1524" layer="91"/>
<wire x1="-38.1" y1="-10.16" x2="-30.48" y2="-10.16" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND3" gate="1" pin="GND"/>
<wire x1="58.42" y1="2.54" x2="60.96" y2="2.54" width="0.1524" layer="91"/>
<wire x1="60.96" y1="2.54" x2="60.96" y2="0" width="0.1524" layer="91"/>
<pinref part="U$3" gate="G$1" pin="GND"/>
<wire x1="60.96" y1="0" x2="63.5" y2="0" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND4" gate="1" pin="GND"/>
<pinref part="U$3" gate="G$1" pin="CS"/>
<wire x1="58.42" y1="-15.24" x2="63.5" y2="-15.24" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="U$4" gate="G$1" pin="G"/>
<wire x1="63.5" y1="124.46" x2="60.96" y2="124.46" width="0.1524" layer="91"/>
<wire x1="60.96" y1="124.46" x2="60.96" y2="127" width="0.1524" layer="91"/>
<pinref part="GND5" gate="1" pin="GND"/>
<wire x1="60.96" y1="127" x2="55.88" y2="127" width="0.1524" layer="91"/>
</segment>
<segment>
<wire x1="63.5" y1="193.04" x2="60.96" y2="193.04" width="0.1524" layer="91"/>
<wire x1="60.96" y1="193.04" x2="60.96" y2="195.58" width="0.1524" layer="91"/>
<pinref part="GND6" gate="1" pin="GND"/>
<wire x1="60.96" y1="195.58" x2="55.88" y2="195.58" width="0.1524" layer="91"/>
<pinref part="U$5" gate="G$1" pin="G"/>
</segment>
</net>
<net name="5V_SCU" class="0">
<segment>
<pinref part="U$2" gate="G$1" pin="VCC"/>
<wire x1="63.5" y1="35.56" x2="63.5" y2="25.4" width="0.1524" layer="91"/>
<wire x1="63.5" y1="25.4" x2="81.28" y2="25.4" width="0.1524" layer="91"/>
<label x="71.12" y="25.4" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="VIN"/>
<wire x1="-30.48" y1="40.64" x2="-45.72" y2="40.64" width="0.1524" layer="91"/>
<label x="-45.72" y="40.64" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$3" gate="G$1" pin="VIN"/>
<wire x1="63.5" y1="10.16" x2="63.5" y2="17.78" width="0.1524" layer="91"/>
<wire x1="63.5" y1="17.78" x2="81.28" y2="17.78" width="0.1524" layer="91"/>
<label x="71.12" y="17.78" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$4" gate="G$1" pin="V"/>
<wire x1="63.5" y1="129.54" x2="63.5" y2="137.16" width="0.1524" layer="91"/>
<wire x1="63.5" y1="137.16" x2="93.98" y2="137.16" width="0.1524" layer="91"/>
<label x="73.66" y="137.16" size="1.778" layer="95"/>
</segment>
<segment>
<wire x1="63.5" y1="198.12" x2="63.5" y2="205.74" width="0.1524" layer="91"/>
<wire x1="63.5" y1="205.74" x2="93.98" y2="205.74" width="0.1524" layer="91"/>
<label x="73.66" y="205.74" size="1.778" layer="95"/>
<pinref part="U$5" gate="G$1" pin="V"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<wire x1="43.18" y1="-25.4" x2="43.18" y2="10.16" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="PA6"/>
<wire x1="43.18" y1="10.16" x2="30.48" y2="10.16" width="0.1524" layer="91"/>
<pinref part="U$3" gate="G$1" pin="SAD"/>
<wire x1="63.5" y1="-20.32" x2="60.96" y2="-20.32" width="0.1524" layer="91"/>
<wire x1="60.96" y1="-20.32" x2="60.96" y2="-25.4" width="0.1524" layer="91"/>
<wire x1="60.96" y1="-25.4" x2="43.18" y2="-25.4" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="SCL"/>
<wire x1="63.5" y1="-5.08" x2="38.1" y2="-5.08" width="0.1524" layer="91"/>
<wire x1="38.1" y1="-5.08" x2="38.1" y2="0" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="PA5"/>
<wire x1="38.1" y1="0" x2="30.48" y2="0" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="SDA"/>
<pinref part="U$1" gate="G$1" pin="PA7"/>
<wire x1="63.5" y1="-10.16" x2="30.48" y2="-10.16" width="0.1524" layer="91"/>
</segment>
</net>
<net name="MAG_DATA" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="SDX"/>
<wire x1="91.44" y1="-15.24" x2="109.22" y2="-15.24" width="0.1524" layer="91"/>
<label x="96.52" y="-15.24" size="1.778" layer="95"/>
</segment>
</net>
<net name="MAG_CLOCK" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="SCX"/>
<wire x1="91.44" y1="-10.16" x2="109.22" y2="-10.16" width="0.1524" layer="91"/>
<label x="96.52" y="-10.16" size="1.778" layer="95"/>
</segment>
</net>
<net name="MAG_CS" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="OCS"/>
<wire x1="91.44" y1="5.08" x2="109.22" y2="5.08" width="0.1524" layer="91"/>
<label x="96.52" y="5.08" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$1" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="PB8"/>
<wire x1="30.48" y1="5.08" x2="50.8" y2="5.08" width="0.1524" layer="91"/>
<wire x1="50.8" y1="5.08" x2="50.8" y2="45.72" width="0.1524" layer="91"/>
<pinref part="U$2" gate="G$1" pin="SCL"/>
<wire x1="50.8" y1="45.72" x2="63.5" y2="45.72" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="PB9"/>
<wire x1="15.24" y1="66.04" x2="50.8" y2="66.04" width="0.1524" layer="91"/>
<wire x1="50.8" y1="66.04" x2="50.8" y2="50.8" width="0.1524" layer="91"/>
<pinref part="U$2" gate="G$1" pin="SDA"/>
<wire x1="50.8" y1="50.8" x2="63.5" y2="50.8" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="PA8"/>
<wire x1="30.48" y1="40.64" x2="33.02" y2="40.64" width="0.1524" layer="91"/>
<pinref part="U$4" gate="G$1" pin="SCL"/>
<wire x1="33.02" y1="40.64" x2="33.02" y2="119.38" width="0.1524" layer="91"/>
<wire x1="33.02" y1="119.38" x2="63.5" y2="119.38" width="0.1524" layer="91"/>
<pinref part="U$5" gate="G$1" pin="SCL"/>
<wire x1="33.02" y1="119.38" x2="33.02" y2="187.96" width="0.1524" layer="91"/>
<wire x1="33.02" y1="187.96" x2="63.5" y2="187.96" width="0.1524" layer="91"/>
<junction x="33.02" y="119.38"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="PC9"/>
<wire x1="-30.48" y1="35.56" x2="-48.26" y2="35.56" width="0.1524" layer="91"/>
<wire x1="-48.26" y1="35.56" x2="-48.26" y2="119.38" width="0.1524" layer="91"/>
<wire x1="-48.26" y1="119.38" x2="27.94" y2="119.38" width="0.1524" layer="91"/>
<wire x1="27.94" y1="119.38" x2="27.94" y2="114.3" width="0.1524" layer="91"/>
<pinref part="U$4" gate="G$1" pin="SDA"/>
<wire x1="27.94" y1="114.3" x2="63.5" y2="114.3" width="0.1524" layer="91"/>
<pinref part="U$5" gate="G$1" pin="SDA"/>
<wire x1="27.94" y1="119.38" x2="27.94" y2="182.88" width="0.1524" layer="91"/>
<wire x1="27.94" y1="182.88" x2="63.5" y2="182.88" width="0.1524" layer="91"/>
<junction x="27.94" y="119.38"/>
</segment>
</net>
<net name="LIGHT0" class="0">
<segment>
<pinref part="U$5" gate="G$1" pin="A0"/>
<wire x1="63.5" y1="167.64" x2="38.1" y2="167.64" width="0.1524" layer="91"/>
<label x="38.1" y="167.64" size="1.778" layer="95"/>
</segment>
</net>
<net name="LIGHT2" class="0">
<segment>
<pinref part="U$5" gate="G$1" pin="A2"/>
<wire x1="63.5" y1="157.48" x2="38.1" y2="157.48" width="0.1524" layer="91"/>
<label x="38.1" y="157.48" size="1.778" layer="95"/>
</segment>
</net>
<net name="LIGHT4" class="0">
<segment>
<pinref part="U$4" gate="G$1" pin="A0"/>
<wire x1="63.5" y1="99.06" x2="38.1" y2="99.06" width="0.1524" layer="91"/>
<label x="38.1" y="99.06" size="1.778" layer="95"/>
</segment>
</net>
<net name="LIGHT6" class="0">
<segment>
<pinref part="U$4" gate="G$1" pin="A2"/>
<wire x1="63.5" y1="88.9" x2="38.1" y2="88.9" width="0.1524" layer="91"/>
<label x="38.1" y="88.9" size="1.778" layer="95"/>
</segment>
</net>
<net name="LIGHT7" class="0">
<segment>
<pinref part="U$4" gate="G$1" pin="A3"/>
<wire x1="38.1" y1="83.82" x2="63.5" y2="83.82" width="0.1524" layer="91"/>
<label x="38.1" y="83.82" size="1.778" layer="95"/>
</segment>
</net>
<net name="LIGHT5" class="0">
<segment>
<pinref part="U$4" gate="G$1" pin="A1"/>
<wire x1="38.1" y1="93.98" x2="63.5" y2="93.98" width="0.1524" layer="91"/>
<label x="38.1" y="93.98" size="1.778" layer="95"/>
</segment>
</net>
<net name="LIGHT3" class="0">
<segment>
<pinref part="U$5" gate="G$1" pin="A3"/>
<wire x1="38.1" y1="152.4" x2="63.5" y2="152.4" width="0.1524" layer="91"/>
<label x="38.1" y="152.4" size="1.778" layer="95"/>
</segment>
</net>
<net name="LIGHT1" class="0">
<segment>
<pinref part="U$5" gate="G$1" pin="A1"/>
<wire x1="38.1" y1="162.56" x2="63.5" y2="162.56" width="0.1524" layer="91"/>
<label x="38.1" y="162.56" size="1.778" layer="95"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
