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
<layer number="99" name="SpiceOrder" color="7" fill="1" visible="yes" active="yes"/>
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
<library name="con-jst-eh">
<description>&lt;b&gt;JST Connectors&lt;/b&gt; - EH 2.5 MM Series&lt;p&gt;
&lt;p&gt;THIS LIBRARY IS PROVIDED AS IS AND WITHOUT WARRANTY OF ANY KIND, EXPRESSED OR IMPLIED.&lt;br&gt;
USE AT YOUR OWN RISK!&lt;p&gt;
&lt;author&gt;Copyright (C) 2016, Bob Starr&lt;br&gt; http://www.bobstarr.net&lt;br&gt;&lt;/author&gt;</description>
<packages>
<package name="B6B-EH-A">
<description>&lt;b&gt;HEADER&lt;/b&gt;</description>
<pad name="1" x="-6.25" y="0" drill="1.016" shape="square" rot="R90"/>
<pad name="2" x="-3.75" y="0" drill="1.016" shape="octagon" rot="R90"/>
<pad name="3" x="-1.25" y="0" drill="1.016" shape="octagon" rot="R90"/>
<pad name="4" x="1.25" y="0" drill="1.016" shape="octagon" rot="R90"/>
<pad name="5" x="3.75" y="0" drill="1.016" shape="octagon" rot="R90"/>
<pad name="6" x="6.25" y="0" drill="1.016" shape="octagon" rot="R90"/>
<text x="-7.747" y="2.159" size="1.016" layer="25" ratio="18">&gt;NAME</text>
<text x="-7.747" y="-3.683" size="1.016" layer="27" ratio="10">&gt;VALUE</text>
<wire x1="-7.56" y1="1.6" x2="7.56" y2="1.6" width="0.0508" layer="51"/>
<wire x1="7.56" y1="1.6" x2="7.56" y2="-2.2" width="0.0508" layer="51"/>
<wire x1="7.56" y1="-2.2" x2="5.71" y2="-2.2" width="0.0508" layer="51"/>
<wire x1="5.71" y1="-2.2" x2="-5.71" y2="-2.2" width="0.0508" layer="51"/>
<wire x1="-5.71" y1="-2.2" x2="-7.56" y2="-2.2" width="0.0508" layer="51"/>
<wire x1="-7.56" y1="-2.2" x2="-7.56" y2="1.6" width="0.0508" layer="51"/>
<wire x1="-7.21" y1="1.3" x2="7.21" y2="1.3" width="0.0508" layer="51"/>
<wire x1="7.21" y1="1.3" x2="7.21" y2="-1.8" width="0.0508" layer="51"/>
<wire x1="7.21" y1="-1.8" x2="5.71" y2="-1.8" width="0.0508" layer="51"/>
<wire x1="5.71" y1="-1.8" x2="5.71" y2="-2.2" width="0.0508" layer="51"/>
<wire x1="-7.21" y1="1.3" x2="-7.21" y2="-1.8" width="0.0508" layer="51"/>
<wire x1="-7.21" y1="-1.8" x2="-5.71" y2="-1.8" width="0.0508" layer="51"/>
<wire x1="-5.71" y1="-1.8" x2="-5.71" y2="-2.2" width="0.0508" layer="51"/>
<wire x1="-7.76" y1="1.8" x2="7.76" y2="1.8" width="0.2032" layer="21"/>
<wire x1="7.76" y1="1.8" x2="7.76" y2="-2.4" width="0.2032" layer="21"/>
<wire x1="7.76" y1="-2.4" x2="-7.76" y2="-2.4" width="0.2032" layer="21"/>
<wire x1="-7.76" y1="-2.4" x2="-7.76" y2="1.8" width="0.2032" layer="21"/>
</package>
<package name="B7B-EH-A">
<description>&lt;b&gt;HEADER&lt;/b&gt;</description>
<pad name="1" x="-7.5" y="0" drill="1.016" shape="square" rot="R90"/>
<pad name="2" x="-5" y="0" drill="1.016" shape="octagon" rot="R90"/>
<pad name="3" x="-2.5" y="0" drill="1.016" shape="octagon" rot="R90"/>
<pad name="4" x="0" y="0" drill="1.016" shape="octagon" rot="R90"/>
<pad name="5" x="2.5" y="0" drill="1.016" shape="octagon" rot="R90"/>
<pad name="6" x="5" y="0" drill="1.016" shape="octagon" rot="R90"/>
<pad name="7" x="7.5" y="0" drill="1.016" shape="octagon" rot="R90"/>
<text x="-9.017" y="2.159" size="1.016" layer="25" ratio="18">&gt;NAME</text>
<text x="-9.017" y="-3.683" size="1.016" layer="27" ratio="10">&gt;VALUE</text>
<wire x1="-8.83" y1="1.6" x2="8.83" y2="1.6" width="0.0508" layer="51"/>
<wire x1="8.83" y1="1.6" x2="8.83" y2="-2.2" width="0.0508" layer="51"/>
<wire x1="8.83" y1="-2.2" x2="6.98" y2="-2.2" width="0.0508" layer="51"/>
<wire x1="6.98" y1="-2.2" x2="-6.98" y2="-2.2" width="0.0508" layer="51"/>
<wire x1="-6.98" y1="-2.2" x2="-8.83" y2="-2.2" width="0.0508" layer="51"/>
<wire x1="-8.83" y1="-2.2" x2="-8.83" y2="1.6" width="0.0508" layer="51"/>
<wire x1="-8.48" y1="1.3" x2="8.48" y2="1.3" width="0.0508" layer="51"/>
<wire x1="8.48" y1="1.3" x2="8.48" y2="-1.8" width="0.0508" layer="51"/>
<wire x1="8.48" y1="-1.8" x2="6.98" y2="-1.8" width="0.0508" layer="51"/>
<wire x1="6.98" y1="-1.8" x2="6.98" y2="-2.2" width="0.0508" layer="51"/>
<wire x1="-8.48" y1="1.3" x2="-8.48" y2="-1.8" width="0.0508" layer="51"/>
<wire x1="-8.48" y1="-1.8" x2="-6.98" y2="-1.8" width="0.0508" layer="51"/>
<wire x1="-6.98" y1="-1.8" x2="-6.98" y2="-2.2" width="0.0508" layer="51"/>
<wire x1="-9.03" y1="1.8" x2="9.03" y2="1.8" width="0.2032" layer="21"/>
<wire x1="9.03" y1="1.8" x2="9.03" y2="-2.4" width="0.2032" layer="21"/>
<wire x1="9.03" y1="-2.4" x2="-9.03" y2="-2.4" width="0.2032" layer="21"/>
<wire x1="-9.03" y1="-2.4" x2="-9.03" y2="1.8" width="0.2032" layer="21"/>
</package>
<package name="B5B-EH-A">
<description>&lt;b&gt;HEADER&lt;/b&gt;</description>
<pad name="1" x="-5" y="0" drill="1.016" shape="square" rot="R90"/>
<pad name="2" x="-2.5" y="0" drill="1.016" shape="octagon" rot="R90"/>
<pad name="3" x="0" y="0" drill="1.016" shape="octagon" rot="R90"/>
<pad name="4" x="2.5" y="0" drill="1.016" shape="octagon" rot="R90"/>
<pad name="5" x="5" y="0" drill="1.016" shape="octagon" rot="R90"/>
<text x="-6.477" y="2.159" size="1.016" layer="25" ratio="18">&gt;NAME</text>
<text x="-6.477" y="-3.683" size="1.016" layer="27" ratio="10">&gt;VALUE</text>
<wire x1="-6.29" y1="1.6" x2="6.29" y2="1.6" width="0.0508" layer="51"/>
<wire x1="6.29" y1="1.6" x2="6.29" y2="-2.2" width="0.0508" layer="51"/>
<wire x1="6.29" y1="-2.2" x2="4.44" y2="-2.2" width="0.0508" layer="51"/>
<wire x1="4.44" y1="-2.2" x2="-4.44" y2="-2.2" width="0.0508" layer="51"/>
<wire x1="-4.44" y1="-2.2" x2="-6.29" y2="-2.2" width="0.0508" layer="51"/>
<wire x1="-6.29" y1="-2.2" x2="-6.29" y2="1.6" width="0.0508" layer="51"/>
<wire x1="-5.94" y1="1.3" x2="5.94" y2="1.3" width="0.0508" layer="51"/>
<wire x1="5.94" y1="1.3" x2="5.94" y2="-1.8" width="0.0508" layer="51"/>
<wire x1="5.94" y1="-1.8" x2="4.44" y2="-1.8" width="0.0508" layer="51"/>
<wire x1="4.44" y1="-1.8" x2="4.44" y2="-2.2" width="0.0508" layer="51"/>
<wire x1="-5.94" y1="1.3" x2="-5.94" y2="-1.8" width="0.0508" layer="51"/>
<wire x1="-5.94" y1="-1.8" x2="-4.44" y2="-1.8" width="0.0508" layer="51"/>
<wire x1="-4.44" y1="-1.8" x2="-4.44" y2="-2.2" width="0.0508" layer="51"/>
<wire x1="-6.49" y1="1.8" x2="6.49" y2="1.8" width="0.2032" layer="21"/>
<wire x1="6.49" y1="1.8" x2="6.49" y2="-2.4" width="0.2032" layer="21"/>
<wire x1="6.49" y1="-2.4" x2="-6.49" y2="-2.4" width="0.2032" layer="21"/>
<wire x1="-6.49" y1="-2.4" x2="-6.49" y2="1.8" width="0.2032" layer="21"/>
</package>
<package name="B4B-EH-A">
<description>&lt;b&gt;HEADER&lt;/b&gt;</description>
<pad name="1" x="-3.75" y="0" drill="1.016" shape="square" rot="R90"/>
<pad name="2" x="-1.25" y="0" drill="1.016" shape="octagon" rot="R90"/>
<pad name="3" x="1.25" y="0" drill="1.016" shape="octagon" rot="R90"/>
<pad name="4" x="3.75" y="0" drill="1.016" shape="octagon" rot="R90"/>
<text x="-5.207" y="2.159" size="1.016" layer="25" ratio="18">&gt;NAME</text>
<text x="-5.207" y="-3.683" size="1.016" layer="27" ratio="10">&gt;VALUE</text>
<wire x1="-5.02" y1="1.6" x2="5.02" y2="1.6" width="0.0508" layer="51"/>
<wire x1="5.02" y1="1.6" x2="5.02" y2="-2.2" width="0.0508" layer="51"/>
<wire x1="5.02" y1="-2.2" x2="3.17" y2="-2.2" width="0.0508" layer="51"/>
<wire x1="3.17" y1="-2.2" x2="-3.17" y2="-2.2" width="0.0508" layer="51"/>
<wire x1="-3.17" y1="-2.2" x2="-5.02" y2="-2.2" width="0.0508" layer="51"/>
<wire x1="-5.02" y1="-2.2" x2="-5.02" y2="1.6" width="0.0508" layer="51"/>
<wire x1="-4.67" y1="1.3" x2="4.67" y2="1.3" width="0.0508" layer="51"/>
<wire x1="4.67" y1="1.3" x2="4.67" y2="-1.8" width="0.0508" layer="51"/>
<wire x1="4.67" y1="-1.8" x2="3.17" y2="-1.8" width="0.0508" layer="51"/>
<wire x1="3.17" y1="-1.8" x2="3.17" y2="-2.2" width="0.0508" layer="51"/>
<wire x1="-4.67" y1="1.3" x2="-4.67" y2="-1.8" width="0.0508" layer="51"/>
<wire x1="-4.67" y1="-1.8" x2="-3.17" y2="-1.8" width="0.0508" layer="51"/>
<wire x1="-3.17" y1="-1.8" x2="-3.17" y2="-2.2" width="0.0508" layer="51"/>
<wire x1="-5.22" y1="1.8" x2="5.22" y2="1.8" width="0.2032" layer="21"/>
<wire x1="5.22" y1="1.8" x2="5.22" y2="-2.4" width="0.2032" layer="21"/>
<wire x1="5.22" y1="-2.4" x2="-5.22" y2="-2.4" width="0.2032" layer="21"/>
<wire x1="-5.22" y1="-2.4" x2="-5.22" y2="1.8" width="0.2032" layer="21"/>
</package>
<package name="B3B-EH-A">
<description>&lt;b&gt;HEADER&lt;/b&gt;</description>
<pad name="1" x="-2.5" y="0" drill="1.016" shape="square" rot="R90"/>
<pad name="2" x="0" y="0" drill="1.016" shape="octagon" rot="R90"/>
<pad name="3" x="2.5" y="0" drill="1.016" shape="octagon" rot="R90"/>
<text x="-3.937" y="2.159" size="1.016" layer="25" ratio="18">&gt;NAME</text>
<text x="-3.937" y="-3.683" size="1.016" layer="27" ratio="10">&gt;VALUE</text>
<wire x1="-3.75" y1="1.6" x2="3.75" y2="1.6" width="0.0508" layer="51"/>
<wire x1="3.75" y1="1.6" x2="3.75" y2="-2.2" width="0.0508" layer="51"/>
<wire x1="3.75" y1="-2.2" x2="1.9" y2="-2.2" width="0.0508" layer="51"/>
<wire x1="1.9" y1="-2.2" x2="-1.9" y2="-2.2" width="0.0508" layer="51"/>
<wire x1="-1.9" y1="-2.2" x2="-3.75" y2="-2.2" width="0.0508" layer="51"/>
<wire x1="-3.75" y1="-2.2" x2="-3.75" y2="1.6" width="0.0508" layer="51"/>
<wire x1="-3.4" y1="1.3" x2="3.4" y2="1.3" width="0.0508" layer="51"/>
<wire x1="3.4" y1="1.3" x2="3.4" y2="-1.8" width="0.0508" layer="51"/>
<wire x1="3.4" y1="-1.8" x2="1.9" y2="-1.8" width="0.0508" layer="51"/>
<wire x1="1.9" y1="-1.8" x2="1.9" y2="-2.2" width="0.0508" layer="51"/>
<wire x1="-3.4" y1="1.3" x2="-3.4" y2="-1.8" width="0.0508" layer="51"/>
<wire x1="-3.4" y1="-1.8" x2="-1.9" y2="-1.8" width="0.0508" layer="51"/>
<wire x1="-1.9" y1="-1.8" x2="-1.9" y2="-2.2" width="0.0508" layer="51"/>
<wire x1="-3.95" y1="1.8" x2="3.95" y2="1.8" width="0.2032" layer="21"/>
<wire x1="3.95" y1="1.8" x2="3.95" y2="-2.4" width="0.2032" layer="21"/>
<wire x1="3.95" y1="-2.4" x2="-3.95" y2="-2.4" width="0.2032" layer="21"/>
<wire x1="-3.95" y1="-2.4" x2="-3.95" y2="1.8" width="0.2032" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="ME06-1">
<pin name="1" x="-5.08" y="7.62" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<wire x1="1.27" y1="7.62" x2="0" y2="7.62" width="0.6096" layer="94"/>
<pin name="2" x="-5.08" y="5.08" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<wire x1="1.27" y1="5.08" x2="0" y2="5.08" width="0.6096" layer="94"/>
<pin name="3" x="-5.08" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<wire x1="1.27" y1="2.54" x2="0" y2="2.54" width="0.6096" layer="94"/>
<pin name="4" x="-5.08" y="0" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<wire x1="1.27" y1="0" x2="0" y2="0" width="0.6096" layer="94"/>
<pin name="5" x="-5.08" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<wire x1="1.27" y1="-2.54" x2="0" y2="-2.54" width="0.6096" layer="94"/>
<pin name="6" x="-5.08" y="-5.08" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<wire x1="1.27" y1="-5.08" x2="0" y2="-5.08" width="0.6096" layer="94"/>
<wire x1="-1.27" y1="10.16" x2="3.81" y2="10.16" width="0.4064" layer="94"/>
<wire x1="-1.27" y1="10.16" x2="-1.27" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="3.81" y1="10.16" x2="3.81" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="-1.27" y1="-7.62" x2="3.81" y2="-7.62" width="0.4064" layer="94"/>
<text x="-1.27" y="10.795" size="1.778" layer="95">&gt;NAME</text>
<text x="-1.27" y="-10.16" size="1.778" layer="95">&gt;VALUE</text>
</symbol>
<symbol name="ME07-1">
<pin name="1" x="-5.08" y="7.62" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<wire x1="1.27" y1="7.62" x2="0" y2="7.62" width="0.6096" layer="94"/>
<pin name="2" x="-5.08" y="5.08" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<wire x1="1.27" y1="5.08" x2="0" y2="5.08" width="0.6096" layer="94"/>
<pin name="3" x="-5.08" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<wire x1="1.27" y1="2.54" x2="0" y2="2.54" width="0.6096" layer="94"/>
<pin name="4" x="-5.08" y="0" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<wire x1="1.27" y1="0" x2="0" y2="0" width="0.6096" layer="94"/>
<pin name="5" x="-5.08" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<wire x1="1.27" y1="-2.54" x2="0" y2="-2.54" width="0.6096" layer="94"/>
<pin name="6" x="-5.08" y="-5.08" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<wire x1="1.27" y1="-5.08" x2="0" y2="-5.08" width="0.6096" layer="94"/>
<pin name="7" x="-5.08" y="-7.62" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<wire x1="1.27" y1="-7.62" x2="0" y2="-7.62" width="0.6096" layer="94"/>
<wire x1="-1.27" y1="10.16" x2="3.81" y2="10.16" width="0.4064" layer="94"/>
<wire x1="-1.27" y1="10.16" x2="-1.27" y2="-10.16" width="0.4064" layer="94"/>
<wire x1="3.81" y1="10.16" x2="3.81" y2="-10.16" width="0.4064" layer="94"/>
<wire x1="-1.27" y1="-10.16" x2="3.81" y2="-10.16" width="0.4064" layer="94"/>
<text x="-1.27" y="10.795" size="1.778" layer="95">&gt;NAME</text>
<text x="-1.27" y="-12.7" size="1.778" layer="95">&gt;VALUE</text>
</symbol>
<symbol name="ME05-1">
<pin name="1" x="-5.08" y="5.08" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<wire x1="1.27" y1="5.08" x2="0" y2="5.08" width="0.6096" layer="94"/>
<pin name="2" x="-5.08" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<wire x1="1.27" y1="2.54" x2="0" y2="2.54" width="0.6096" layer="94"/>
<pin name="3" x="-5.08" y="0" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<wire x1="1.27" y1="0" x2="0" y2="0" width="0.6096" layer="94"/>
<pin name="4" x="-5.08" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<wire x1="1.27" y1="-2.54" x2="0" y2="-2.54" width="0.6096" layer="94"/>
<pin name="5" x="-5.08" y="-5.08" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<wire x1="1.27" y1="-5.08" x2="0" y2="-5.08" width="0.6096" layer="94"/>
<wire x1="-1.27" y1="7.62" x2="3.81" y2="7.62" width="0.4064" layer="94"/>
<wire x1="-1.27" y1="7.62" x2="-1.27" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="3.81" y1="7.62" x2="3.81" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="-1.27" y1="-7.62" x2="3.81" y2="-7.62" width="0.4064" layer="94"/>
<text x="-1.27" y="8.255" size="1.778" layer="95">&gt;NAME</text>
<text x="-1.27" y="-10.16" size="1.778" layer="95">&gt;VALUE</text>
</symbol>
<symbol name="ME04-1">
<pin name="1" x="-5.08" y="5.08" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<wire x1="1.27" y1="5.08" x2="0" y2="5.08" width="0.6096" layer="94"/>
<pin name="2" x="-5.08" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<wire x1="1.27" y1="2.54" x2="0" y2="2.54" width="0.6096" layer="94"/>
<pin name="3" x="-5.08" y="0" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<wire x1="1.27" y1="0" x2="0" y2="0" width="0.6096" layer="94"/>
<pin name="4" x="-5.08" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<wire x1="1.27" y1="-2.54" x2="0" y2="-2.54" width="0.6096" layer="94"/>
<wire x1="-1.27" y1="7.62" x2="3.81" y2="7.62" width="0.4064" layer="94"/>
<wire x1="-1.27" y1="7.62" x2="-1.27" y2="-5.08" width="0.4064" layer="94"/>
<wire x1="3.81" y1="7.62" x2="3.81" y2="-5.08" width="0.4064" layer="94"/>
<wire x1="-1.27" y1="-5.08" x2="3.81" y2="-5.08" width="0.4064" layer="94"/>
<text x="-1.27" y="8.255" size="1.778" layer="95">&gt;NAME</text>
<text x="-1.27" y="-7.62" size="1.778" layer="95">&gt;VALUE</text>
</symbol>
<symbol name="ME03-1">
<pin name="1" x="-5.08" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<wire x1="1.27" y1="2.54" x2="0" y2="2.54" width="0.6096" layer="94"/>
<pin name="2" x="-5.08" y="0" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<wire x1="1.27" y1="0" x2="0" y2="0" width="0.6096" layer="94"/>
<pin name="3" x="-5.08" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<wire x1="1.27" y1="-2.54" x2="0" y2="-2.54" width="0.6096" layer="94"/>
<wire x1="-1.27" y1="5.08" x2="3.81" y2="5.08" width="0.4064" layer="94"/>
<wire x1="-1.27" y1="5.08" x2="-1.27" y2="-5.08" width="0.4064" layer="94"/>
<wire x1="3.81" y1="5.08" x2="3.81" y2="-5.08" width="0.4064" layer="94"/>
<wire x1="-1.27" y1="-5.08" x2="3.81" y2="-5.08" width="0.4064" layer="94"/>
<text x="-1.27" y="5.715" size="1.778" layer="95">&gt;NAME</text>
<text x="-1.27" y="-7.62" size="1.778" layer="95">&gt;VALUE</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="B6B-EH-A" prefix="P">
<description>&lt;b&gt;HEADER&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="ME06-1" x="0" y="0" swaplevel="1"/>
</gates>
<devices>
<device name="" package="B6B-EH-A">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="B7B-EH-A" prefix="P">
<description>&lt;b&gt;HEADER&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="ME07-1" x="0" y="0" swaplevel="1"/>
</gates>
<devices>
<device name="" package="B7B-EH-A">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="B5B-EH-A" prefix="P">
<description>&lt;b&gt;HEADER&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="ME05-1" x="0" y="0" swaplevel="1"/>
</gates>
<devices>
<device name="" package="B5B-EH-A">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="B4B-EH-A" prefix="P">
<description>&lt;b&gt;HEADER&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="ME04-1" x="0" y="0" swaplevel="1"/>
</gates>
<devices>
<device name="" package="B4B-EH-A">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="B3B-EH-A" prefix="P">
<description>&lt;b&gt;HEADER&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="ME03-1" x="0" y="0" swaplevel="1"/>
</gates>
<devices>
<device name="" package="B3B-EH-A">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="MCP2551">
<packages>
<package name="SOIC-8">
<smd name="TXD" x="-2.54" y="1.905" dx="1.27" dy="0.635" layer="1" rot="R180"/>
<smd name="VSS" x="-2.54" y="0.635" dx="1.27" dy="0.635" layer="1" rot="R180"/>
<smd name="VDD" x="-2.54" y="-0.635" dx="1.27" dy="0.635" layer="1" rot="R180"/>
<smd name="RXD" x="-2.54" y="-1.905" dx="1.27" dy="0.635" layer="1" rot="R180"/>
<smd name="VREF" x="2.54" y="-1.905" dx="1.27" dy="0.635" layer="1"/>
<smd name="CANL" x="2.54" y="-0.635" dx="1.27" dy="0.635" layer="1"/>
<smd name="CANH" x="2.54" y="0.635" dx="1.27" dy="0.635" layer="1"/>
<smd name="RS" x="2.54" y="1.905" dx="1.27" dy="0.635" layer="1"/>
<wire x1="1.905" y1="2.54" x2="-1.905" y2="2.54" width="0.127" layer="21"/>
<wire x1="-1.905" y1="2.54" x2="-1.905" y2="-2.54" width="0.127" layer="21"/>
<wire x1="-1.905" y1="-2.54" x2="1.905" y2="-2.54" width="0.127" layer="21"/>
<wire x1="1.905" y1="-2.54" x2="1.905" y2="2.54" width="0.127" layer="21"/>
<text x="-2.54" y="3.175" size="1.016" layer="25">MCP2551</text>
<circle x="-1.27" y="1.905" radius="0.127" width="0.127" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="MCP2551">
<description>The MCP2551 is a high-speed CAN, fault-tolerant device that serves as the interface between a CAN 
protocol controller and the physical bus. The MCP2551 provides differential transmit and receive capability 
for the CAN protocol controller and is fully compatible with the ISO-11898 standard, including 24V requirements.  It will operate at speeds of up to 1 Mb/s. Typically, each node in a CAN system must have a device to convert the digital signals generated by a CAN controller to signals suitable for transmission over the bus cabling (differential output). It also provides a buffer between the CAN controller and the high-voltage spikes that can be generated on the CAN bus by outside sources (EMI, ESD, electrical transients, etc.).</description>
<pin name="TXD" x="-15.24" y="2.54" visible="pin" length="middle"/>
<pin name="VSS" x="-15.24" y="0" visible="pin" length="middle"/>
<pin name="VDD" x="-15.24" y="-2.54" visible="pin" length="middle"/>
<pin name="RXD" x="-15.24" y="-5.08" visible="pin" length="middle"/>
<pin name="VREF" x="17.78" y="-5.08" visible="pin" length="middle" rot="R180"/>
<pin name="CANL" x="17.78" y="-2.54" visible="pin" length="middle" rot="R180"/>
<pin name="CANH" x="17.78" y="0" visible="pin" length="middle" rot="R180"/>
<pin name="RS" x="17.78" y="2.54" visible="pin" length="middle" rot="R180"/>
<circle x="-7.62" y="5.08" radius="0.508" width="0.127" layer="94"/>
<wire x1="-10.16" y1="7.62" x2="-10.16" y2="-10.16" width="0.254" layer="94"/>
<wire x1="-10.16" y1="-10.16" x2="12.7" y2="-10.16" width="0.254" layer="94"/>
<wire x1="12.7" y1="-10.16" x2="12.7" y2="7.62" width="0.254" layer="94"/>
<wire x1="-10.16" y1="7.62" x2="12.7" y2="7.62" width="0.254" layer="94"/>
<text x="-5.08" y="-12.7" size="1.778" layer="95">MCP2551</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="MCP2551">
<description>The MCP2551 is a high-speed CAN, fault-tolerant device that serves as the interface 
between a CAN protocol controller and the physical bus. The MCP2551 provides differential 
transmit and receive capability for the CAN protocol controller and is fully compatible with the 
ISO-11898 standard, including 24V requirements. It will operate at speeds of up to 1 Mb/s.
Typically, each node in a CAN system must have a device to convert the digital signals generated by a CAN controller to signals suitable for transmission over the bus cabling (differential output). It also provides a buffer between the CAN controller and the high-voltage spikes that can be generated on the CAN bus by outside sources (EMI, ESD, electrical transients, etc.).</description>
<gates>
<gate name="G$1" symbol="MCP2551" x="-2.54" y="2.54"/>
</gates>
<devices>
<device name="" package="SOIC-8">
<connects>
<connect gate="G$1" pin="CANH" pad="CANH"/>
<connect gate="G$1" pin="CANL" pad="CANL"/>
<connect gate="G$1" pin="RS" pad="RS"/>
<connect gate="G$1" pin="RXD" pad="RXD"/>
<connect gate="G$1" pin="TXD" pad="TXD"/>
<connect gate="G$1" pin="VDD" pad="VDD"/>
<connect gate="G$1" pin="VREF" pad="VREF"/>
<connect gate="G$1" pin="VSS" pad="VSS"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="ngspice-simulation" urn="urn:adsk.eagle:library:527439">
<description>SPICE compatible library parts</description>
<packages>
</packages>
<symbols>
<symbol name="R" urn="urn:adsk.eagle:symbol:5272030/1" library_version="16">
<description>RESISTOR</description>
<wire x1="-2.54" y1="-0.889" x2="2.54" y2="-0.889" width="0.254" layer="94"/>
<wire x1="2.54" y1="0.889" x2="-2.54" y2="0.889" width="0.254" layer="94"/>
<wire x1="2.54" y1="-0.889" x2="2.54" y2="0.889" width="0.254" layer="94"/>
<wire x1="-2.54" y1="-0.889" x2="-2.54" y2="0.889" width="0.254" layer="94"/>
<pin name="1" x="-5.08" y="0" visible="off" length="short" direction="pas" swaplevel="1"/>
<pin name="2" x="5.08" y="0" visible="off" length="short" direction="pas" swaplevel="1" rot="R180"/>
<text x="-2.54" y="2.54" size="1.778" layer="95">&gt;NAME</text>
<text x="-2.54" y="-6.35" size="1.778" layer="97">&gt;SPICEMODEL</text>
<text x="-2.54" y="-3.81" size="1.778" layer="96">&gt;VALUE</text>
<text x="-2.54" y="-8.89" size="1.778" layer="97">&gt;SPICEEXTRA</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="R" urn="urn:adsk.eagle:component:5272053/1" prefix="R" uservalue="yes" library_version="16">
<description>RESISTOR</description>
<gates>
<gate name="G$1" symbol="R" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name="">
<attribute name="_EXTERNAL_" value="" constant="no"/>
</technology>
</technologies>
</device>
</devices>
<spice>
<pinmapping spiceprefix="R">
<pinmap gate="G$1" pin="1" pinorder="1"/>
<pinmap gate="G$1" pin="2" pinorder="2"/>
</pinmapping>
</spice>
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
<part name="P1" library="con-jst-eh" deviceset="B6B-EH-A" device=""/>
<part name="GND7" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="P2" library="con-jst-eh" deviceset="B6B-EH-A" device=""/>
<part name="GND8" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="P3" library="con-jst-eh" deviceset="B7B-EH-A" device=""/>
<part name="GND9" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="U$6" library="MCP2551" deviceset="MCP2551" device=""/>
<part name="GND10" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="R1" library="ngspice-simulation" library_urn="urn:adsk.eagle:library:527439" deviceset="R" device=""/>
<part name="GND11" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="P4" library="con-jst-eh" deviceset="B5B-EH-A" device=""/>
<part name="P6" library="con-jst-eh" deviceset="B4B-EH-A" device=""/>
<part name="GND12" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND13" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="P5" library="con-jst-eh" deviceset="B4B-EH-A" device=""/>
<part name="P7" library="con-jst-eh" deviceset="B3B-EH-A" device=""/>
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
<instance part="P1" gate="G$1" x="45.72" y="162.56" smashed="yes" rot="R180">
<attribute name="NAME" x="46.99" y="151.765" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="46.99" y="172.72" size="1.778" layer="95" rot="R180"/>
</instance>
<instance part="GND7" gate="1" x="53.34" y="147.32" smashed="yes">
<attribute name="VALUE" x="50.8" y="144.78" size="1.778" layer="96"/>
</instance>
<instance part="P2" gate="G$1" x="45.72" y="93.98" smashed="yes" rot="R180">
<attribute name="NAME" x="46.99" y="83.185" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="46.99" y="104.14" size="1.778" layer="95" rot="R180"/>
</instance>
<instance part="GND8" gate="1" x="53.34" y="78.74" smashed="yes">
<attribute name="VALUE" x="50.8" y="76.2" size="1.778" layer="96"/>
</instance>
<instance part="P3" gate="G$1" x="134.62" y="-5.08" smashed="yes">
<attribute name="NAME" x="133.35" y="5.715" size="1.778" layer="95"/>
<attribute name="VALUE" x="133.35" y="-17.78" size="1.778" layer="95"/>
</instance>
<instance part="GND9" gate="1" x="147.32" y="2.54" smashed="yes">
<attribute name="VALUE" x="144.78" y="0" size="1.778" layer="96"/>
</instance>
<instance part="U$6" gate="G$1" x="-10.16" y="139.7" smashed="yes" rot="R180"/>
<instance part="GND10" gate="1" x="12.7" y="137.16" smashed="yes">
<attribute name="VALUE" x="10.16" y="134.62" size="1.778" layer="96"/>
</instance>
<instance part="R1" gate="G$1" x="-22.86" y="127" smashed="yes">
<attribute name="NAME" x="-25.4" y="129.54" size="1.778" layer="95"/>
<attribute name="VALUE" x="-25.4" y="123.19" size="1.778" layer="96"/>
</instance>
<instance part="GND11" gate="1" x="-10.16" y="124.46" smashed="yes">
<attribute name="VALUE" x="-12.7" y="121.92" size="1.778" layer="96"/>
</instance>
<instance part="P4" gate="G$1" x="12.7" y="175.26" smashed="yes">
<attribute name="NAME" x="11.43" y="183.515" size="1.778" layer="95"/>
<attribute name="VALUE" x="11.43" y="165.1" size="1.778" layer="95"/>
</instance>
<instance part="P6" gate="G$1" x="-43.18" y="175.26" smashed="yes" rot="R180">
<attribute name="NAME" x="-41.91" y="167.005" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="-41.91" y="182.88" size="1.778" layer="95" rot="R180"/>
</instance>
<instance part="GND12" gate="1" x="-38.1" y="165.1" smashed="yes">
<attribute name="VALUE" x="-40.64" y="162.56" size="1.778" layer="96"/>
</instance>
<instance part="GND13" gate="1" x="5.08" y="165.1" smashed="yes">
<attribute name="VALUE" x="2.54" y="162.56" size="1.778" layer="96"/>
</instance>
<instance part="P5" gate="G$1" x="66.04" y="-53.34" smashed="yes">
<attribute name="NAME" x="64.77" y="-45.085" size="1.778" layer="95"/>
<attribute name="VALUE" x="64.77" y="-60.96" size="1.778" layer="95"/>
</instance>
<instance part="P7" gate="G$1" x="38.1" y="-55.88" smashed="yes" rot="R180">
<attribute name="NAME" x="39.37" y="-61.595" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="39.37" y="-48.26" size="1.778" layer="95" rot="R180"/>
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
<segment>
<pinref part="P1" gate="G$1" pin="1"/>
<wire x1="50.8" y1="154.94" x2="53.34" y2="152.4" width="0.1524" layer="91"/>
<wire x1="53.34" y1="152.4" x2="53.34" y2="149.86" width="0.1524" layer="91"/>
<pinref part="GND7" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="P2" gate="G$1" pin="1"/>
<wire x1="50.8" y1="86.36" x2="53.34" y2="83.82" width="0.1524" layer="91"/>
<wire x1="53.34" y1="83.82" x2="53.34" y2="81.28" width="0.1524" layer="91"/>
<pinref part="GND8" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="P3" gate="G$1" pin="1"/>
<wire x1="129.54" y1="2.54" x2="127" y2="5.08" width="0.1524" layer="91"/>
<wire x1="127" y1="5.08" x2="127" y2="10.16" width="0.1524" layer="91"/>
<wire x1="127" y1="10.16" x2="129.54" y2="12.7" width="0.1524" layer="91"/>
<wire x1="129.54" y1="12.7" x2="144.78" y2="12.7" width="0.1524" layer="91"/>
<wire x1="144.78" y1="12.7" x2="147.32" y2="10.16" width="0.1524" layer="91"/>
<wire x1="147.32" y1="10.16" x2="147.32" y2="5.08" width="0.1524" layer="91"/>
<pinref part="GND9" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="U$6" gate="G$1" pin="VSS"/>
<pinref part="GND10" gate="1" pin="GND"/>
<wire x1="5.08" y1="139.7" x2="12.7" y2="139.7" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="R1" gate="G$1" pin="2"/>
<pinref part="GND11" gate="1" pin="GND"/>
<wire x1="-17.78" y1="127" x2="-10.16" y2="127" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="P6" gate="G$1" pin="1"/>
<pinref part="GND12" gate="1" pin="GND"/>
<wire x1="-38.1" y1="170.18" x2="-38.1" y2="167.64" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND13" gate="1" pin="GND"/>
<pinref part="P4" gate="G$1" pin="5"/>
<wire x1="5.08" y1="167.64" x2="7.62" y2="170.18" width="0.1524" layer="91"/>
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
<segment>
<pinref part="P1" gate="G$1" pin="6"/>
<wire x1="50.8" y1="167.64" x2="55.88" y2="167.64" width="0.1524" layer="91"/>
<wire x1="55.88" y1="167.64" x2="58.42" y2="170.18" width="0.1524" layer="91"/>
<wire x1="58.42" y1="170.18" x2="58.42" y2="175.26" width="0.1524" layer="91"/>
<wire x1="58.42" y1="175.26" x2="55.88" y2="177.8" width="0.1524" layer="91"/>
<wire x1="55.88" y1="177.8" x2="43.18" y2="177.8" width="0.1524" layer="91"/>
<label x="43.18" y="177.8" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="P2" gate="G$1" pin="6"/>
<wire x1="50.8" y1="99.06" x2="55.88" y2="99.06" width="0.1524" layer="91"/>
<wire x1="55.88" y1="99.06" x2="58.42" y2="101.6" width="0.1524" layer="91"/>
<wire x1="58.42" y1="101.6" x2="58.42" y2="106.68" width="0.1524" layer="91"/>
<wire x1="58.42" y1="106.68" x2="55.88" y2="109.22" width="0.1524" layer="91"/>
<wire x1="55.88" y1="109.22" x2="43.18" y2="109.22" width="0.1524" layer="91"/>
<label x="43.18" y="109.22" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="P3" gate="G$1" pin="7"/>
<wire x1="129.54" y1="-12.7" x2="127" y2="-15.24" width="0.1524" layer="91"/>
<wire x1="127" y1="-15.24" x2="127" y2="-20.32" width="0.1524" layer="91"/>
<wire x1="127" y1="-20.32" x2="132.08" y2="-25.4" width="0.1524" layer="91"/>
<wire x1="132.08" y1="-25.4" x2="149.86" y2="-25.4" width="0.1524" layer="91"/>
<label x="139.7" y="-25.4" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="P4" gate="G$1" pin="1"/>
<wire x1="7.62" y1="180.34" x2="-10.16" y2="180.34" width="0.1524" layer="91"/>
<label x="-10.16" y="180.34" size="1.778" layer="95"/>
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
<wire x1="91.44" y1="-15.24" x2="111.76" y2="-15.24" width="0.1524" layer="91"/>
<label x="96.52" y="-15.24" size="1.778" layer="95"/>
<pinref part="P3" gate="G$1" pin="4"/>
<wire x1="111.76" y1="-15.24" x2="121.92" y2="-5.08" width="0.1524" layer="91"/>
<wire x1="121.92" y1="-5.08" x2="129.54" y2="-5.08" width="0.1524" layer="91"/>
</segment>
</net>
<net name="MAG_CLOCK" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="SCX"/>
<wire x1="91.44" y1="-10.16" x2="111.76" y2="-10.16" width="0.1524" layer="91"/>
<label x="96.52" y="-10.16" size="1.778" layer="95"/>
<pinref part="P3" gate="G$1" pin="3"/>
<wire x1="111.76" y1="-10.16" x2="119.38" y2="-2.54" width="0.1524" layer="91"/>
<wire x1="119.38" y1="-2.54" x2="129.54" y2="-2.54" width="0.1524" layer="91"/>
</segment>
</net>
<net name="MAG_CS" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="OCS"/>
<wire x1="91.44" y1="5.08" x2="111.76" y2="5.08" width="0.1524" layer="91"/>
<label x="96.52" y="5.08" size="1.778" layer="95"/>
<pinref part="P3" gate="G$1" pin="2"/>
<wire x1="111.76" y1="5.08" x2="116.84" y2="0" width="0.1524" layer="91"/>
<wire x1="116.84" y1="0" x2="129.54" y2="0" width="0.1524" layer="91"/>
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
<net name="N$8" class="0">
<segment>
<pinref part="U$5" gate="G$1" pin="A0"/>
<wire x1="63.5" y1="167.64" x2="58.42" y2="167.64" width="0.1524" layer="91"/>
<wire x1="58.42" y1="167.64" x2="55.88" y2="165.1" width="0.1524" layer="91"/>
<pinref part="P1" gate="G$1" pin="5"/>
<wire x1="55.88" y1="165.1" x2="50.8" y2="165.1" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$9" class="0">
<segment>
<pinref part="U$5" gate="G$1" pin="A1"/>
<pinref part="P1" gate="G$1" pin="4"/>
<wire x1="63.5" y1="162.56" x2="50.8" y2="162.56" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$10" class="0">
<segment>
<pinref part="P1" gate="G$1" pin="3"/>
<wire x1="50.8" y1="160.02" x2="55.88" y2="160.02" width="0.1524" layer="91"/>
<wire x1="55.88" y1="160.02" x2="58.42" y2="157.48" width="0.1524" layer="91"/>
<pinref part="U$5" gate="G$1" pin="A2"/>
<wire x1="58.42" y1="157.48" x2="63.5" y2="157.48" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$11" class="0">
<segment>
<pinref part="P1" gate="G$1" pin="2"/>
<wire x1="50.8" y1="157.48" x2="53.34" y2="157.48" width="0.1524" layer="91"/>
<pinref part="U$5" gate="G$1" pin="A3"/>
<wire x1="53.34" y1="157.48" x2="58.42" y2="152.4" width="0.1524" layer="91"/>
<wire x1="58.42" y1="152.4" x2="63.5" y2="152.4" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$12" class="0">
<segment>
<wire x1="63.5" y1="99.06" x2="58.42" y2="99.06" width="0.1524" layer="91"/>
<wire x1="58.42" y1="99.06" x2="55.88" y2="96.52" width="0.1524" layer="91"/>
<pinref part="P2" gate="G$1" pin="5"/>
<wire x1="55.88" y1="96.52" x2="50.8" y2="96.52" width="0.1524" layer="91"/>
<pinref part="U$4" gate="G$1" pin="A0"/>
</segment>
</net>
<net name="N$13" class="0">
<segment>
<pinref part="P2" gate="G$1" pin="4"/>
<wire x1="63.5" y1="93.98" x2="50.8" y2="93.98" width="0.1524" layer="91"/>
<pinref part="U$4" gate="G$1" pin="A1"/>
</segment>
</net>
<net name="N$14" class="0">
<segment>
<pinref part="P2" gate="G$1" pin="3"/>
<wire x1="50.8" y1="91.44" x2="55.88" y2="91.44" width="0.1524" layer="91"/>
<wire x1="55.88" y1="91.44" x2="58.42" y2="88.9" width="0.1524" layer="91"/>
<wire x1="58.42" y1="88.9" x2="63.5" y2="88.9" width="0.1524" layer="91"/>
<pinref part="U$4" gate="G$1" pin="A2"/>
</segment>
</net>
<net name="N$15" class="0">
<segment>
<pinref part="P2" gate="G$1" pin="2"/>
<wire x1="50.8" y1="88.9" x2="53.34" y2="88.9" width="0.1524" layer="91"/>
<wire x1="53.34" y1="88.9" x2="58.42" y2="83.82" width="0.1524" layer="91"/>
<wire x1="58.42" y1="83.82" x2="63.5" y2="83.82" width="0.1524" layer="91"/>
<pinref part="U$4" gate="G$1" pin="A3"/>
</segment>
</net>
<net name="N$17" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="PC1"/>
<wire x1="30.48" y1="-5.08" x2="33.02" y2="-5.08" width="0.1524" layer="91"/>
<wire x1="33.02" y1="-5.08" x2="35.56" y2="-7.62" width="0.1524" layer="91"/>
<wire x1="35.56" y1="-7.62" x2="35.56" y2="-27.94" width="0.1524" layer="91"/>
<wire x1="35.56" y1="-27.94" x2="40.64" y2="-33.02" width="0.1524" layer="91"/>
<wire x1="40.64" y1="-33.02" x2="104.14" y2="-33.02" width="0.1524" layer="91"/>
<pinref part="P3" gate="G$1" pin="5"/>
<wire x1="104.14" y1="-33.02" x2="129.54" y2="-7.62" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$18" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="PB1"/>
<wire x1="30.48" y1="-20.32" x2="33.02" y2="-22.86" width="0.1524" layer="91"/>
<wire x1="33.02" y1="-22.86" x2="33.02" y2="-27.94" width="0.1524" layer="91"/>
<wire x1="33.02" y1="-27.94" x2="40.64" y2="-35.56" width="0.1524" layer="91"/>
<wire x1="40.64" y1="-35.56" x2="104.14" y2="-35.56" width="0.1524" layer="91"/>
<pinref part="P3" gate="G$1" pin="6"/>
<wire x1="104.14" y1="-35.56" x2="129.54" y2="-10.16" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$19" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="PA12"/>
<wire x1="15.24" y1="101.6" x2="22.86" y2="101.6" width="0.1524" layer="91"/>
<pinref part="U$6" gate="G$1" pin="TXD"/>
<wire x1="5.08" y1="137.16" x2="10.16" y2="132.08" width="0.1524" layer="91"/>
<wire x1="10.16" y1="132.08" x2="22.86" y2="132.08" width="0.1524" layer="91"/>
<wire x1="22.86" y1="132.08" x2="25.4" y2="129.54" width="0.1524" layer="91"/>
<wire x1="25.4" y1="129.54" x2="25.4" y2="104.14" width="0.1524" layer="91"/>
<wire x1="25.4" y1="104.14" x2="22.86" y2="101.6" width="0.1524" layer="91"/>
</segment>
</net>
<net name="5V_PCU" class="0">
<segment>
<pinref part="U$6" gate="G$1" pin="VDD"/>
<wire x1="5.08" y1="142.24" x2="17.78" y2="142.24" width="0.1524" layer="91"/>
<label x="7.62" y="142.24" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$16" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="PA11"/>
<wire x1="15.24" y1="106.68" x2="17.78" y2="106.68" width="0.1524" layer="91"/>
<wire x1="17.78" y1="106.68" x2="20.32" y2="109.22" width="0.1524" layer="91"/>
<wire x1="20.32" y1="109.22" x2="20.32" y2="142.24" width="0.1524" layer="91"/>
<wire x1="20.32" y1="142.24" x2="17.78" y2="144.78" width="0.1524" layer="91"/>
<pinref part="U$6" gate="G$1" pin="RXD"/>
<wire x1="17.78" y1="144.78" x2="5.08" y2="144.78" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$20" class="0">
<segment>
<pinref part="U$6" gate="G$1" pin="RS"/>
<pinref part="R1" gate="G$1" pin="1"/>
<wire x1="-27.94" y1="137.16" x2="-27.94" y2="127" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$21" class="0">
<segment>
<pinref part="P6" gate="G$1" pin="4"/>
<pinref part="P4" gate="G$1" pin="2"/>
<wire x1="-38.1" y1="177.8" x2="7.62" y2="177.8" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$23" class="0">
<segment>
<pinref part="U$6" gate="G$1" pin="CANH"/>
<wire x1="-27.94" y1="139.7" x2="-33.02" y2="144.78" width="0.1524" layer="91"/>
<pinref part="P6" gate="G$1" pin="3"/>
<pinref part="P4" gate="G$1" pin="3"/>
<wire x1="-38.1" y1="175.26" x2="-33.02" y2="175.26" width="0.1524" layer="91"/>
<wire x1="-33.02" y1="175.26" x2="7.62" y2="175.26" width="0.1524" layer="91"/>
<wire x1="-33.02" y1="144.78" x2="-33.02" y2="175.26" width="0.1524" layer="91"/>
<junction x="-33.02" y="175.26"/>
</segment>
</net>
<net name="N$25" class="0">
<segment>
<pinref part="U$6" gate="G$1" pin="CANL"/>
<wire x1="-27.94" y1="142.24" x2="-30.48" y2="144.78" width="0.1524" layer="91"/>
<pinref part="P4" gate="G$1" pin="4"/>
<pinref part="P6" gate="G$1" pin="2"/>
<wire x1="7.62" y1="172.72" x2="-30.48" y2="172.72" width="0.1524" layer="91"/>
<wire x1="-30.48" y1="172.72" x2="-38.1" y2="172.72" width="0.1524" layer="91"/>
<wire x1="-30.48" y1="144.78" x2="-30.48" y2="172.72" width="0.1524" layer="91"/>
<junction x="-30.48" y="172.72"/>
</segment>
</net>
<net name="N$22" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="SW-DAT"/>
<wire x1="7.62" y1="-38.1" x2="7.62" y2="-35.56" width="0.1524" layer="91"/>
<wire x1="7.62" y1="-35.56" x2="10.16" y2="-33.02" width="0.1524" layer="91"/>
<wire x1="10.16" y1="-33.02" x2="33.02" y2="-33.02" width="0.1524" layer="91"/>
<pinref part="P5" gate="G$1" pin="1"/>
<wire x1="33.02" y1="-33.02" x2="48.26" y2="-48.26" width="0.1524" layer="91"/>
<wire x1="48.26" y1="-48.26" x2="60.96" y2="-48.26" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$24" class="0">
<segment>
<pinref part="P5" gate="G$1" pin="2"/>
<wire x1="60.96" y1="-50.8" x2="45.72" y2="-50.8" width="0.1524" layer="91"/>
<wire x1="45.72" y1="-50.8" x2="25.4" y2="-30.48" width="0.1524" layer="91"/>
<wire x1="25.4" y1="-30.48" x2="5.08" y2="-30.48" width="0.1524" layer="91"/>
<wire x1="5.08" y1="-30.48" x2="2.54" y2="-33.02" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="SW-CLK"/>
<wire x1="2.54" y1="-33.02" x2="2.54" y2="-38.1" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$26" class="0">
<segment>
<pinref part="P5" gate="G$1" pin="3"/>
<pinref part="P7" gate="G$1" pin="3"/>
<wire x1="60.96" y1="-53.34" x2="43.18" y2="-53.34" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$27" class="0">
<segment>
<pinref part="P5" gate="G$1" pin="4"/>
<pinref part="P7" gate="G$1" pin="2"/>
<wire x1="60.96" y1="-55.88" x2="43.18" y2="-55.88" width="0.1524" layer="91"/>
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
<note version="8.4" severity="warning">
Since Version 8.4, EAGLE supports properties for SPICE simulation. 
Probes in schematics and SPICE mapping objects found in parts and library devices
will not be understood with this version. Update EAGLE to the latest version
for full support of SPICE simulation. 
</note>
</compatibility>
</eagle>
