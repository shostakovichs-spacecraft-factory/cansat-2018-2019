<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.3.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="1" fill="3" visible="no" active="no"/>
<layer number="3" name="Route3" color="4" fill="3" visible="no" active="no"/>
<layer number="4" name="Route4" color="1" fill="4" visible="no" active="no"/>
<layer number="5" name="Route5" color="4" fill="4" visible="no" active="no"/>
<layer number="6" name="Route6" color="1" fill="8" visible="no" active="no"/>
<layer number="7" name="Route7" color="4" fill="8" visible="no" active="no"/>
<layer number="8" name="Route8" color="1" fill="2" visible="no" active="no"/>
<layer number="9" name="Route9" color="4" fill="2" visible="no" active="no"/>
<layer number="10" name="Route10" color="1" fill="7" visible="no" active="no"/>
<layer number="11" name="Route11" color="4" fill="7" visible="no" active="no"/>
<layer number="12" name="Route12" color="1" fill="5" visible="no" active="no"/>
<layer number="13" name="Route13" color="4" fill="5" visible="no" active="no"/>
<layer number="14" name="Route14" color="1" fill="6" visible="no" active="no"/>
<layer number="15" name="Route15" color="4" fill="6" visible="no" active="no"/>
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
<package name="ICU">
<rectangle x1="-23.5" y1="-33" x2="23.5" y2="33" layer="21"/>
<hole x="-22" y="31.5" drill="3"/>
<hole x="-22" y="-31.5" drill="3"/>
<hole x="22" y="-31.5" drill="3"/>
<hole x="22" y="31.5" drill="3"/>
<pad name="PE7" x="20.23" y="1.27" drill="0.6" shape="square"/>
<pad name="PD0" x="20.23" y="3.81" drill="0.6" shape="square"/>
<pad name="PD14" x="20.23" y="6.35" drill="0.6" shape="square"/>
<pad name="PD4" x="20.23" y="8.89" drill="0.6" shape="square"/>
<pad name="PD11" x="20.23" y="11.43" drill="0.6" shape="square"/>
<pad name="PB0" x="20.23" y="13.97" drill="0.6" shape="square"/>
<pad name="PB2" x="20.23" y="16.51" drill="0.6" shape="square"/>
<pad name="PB4" x="20.23" y="19.05" drill="0.6" shape="square"/>
<pad name="PB6" x="20.23" y="21.59" drill="0.6" shape="square"/>
<pad name="GND_0" x="20.23" y="24.13" drill="0.6" shape="square"/>
<pad name="3V3_0" x="20.23" y="-24.13" drill="0.6" shape="square"/>
<pad name="PA1" x="20.23" y="-21.59" drill="0.6" shape="square"/>
<pad name="PB15" x="20.23" y="-19.05" drill="0.6" shape="square"/>
<pad name="PB13" x="20.23" y="-16.51" drill="0.6" shape="square"/>
<pad name="PC5" x="20.23" y="-13.97" drill="0.6" shape="square"/>
<pad name="PD9" x="20.23" y="-11.43" drill="0.6" shape="square"/>
<pad name="PE15" x="20.23" y="-8.89" drill="0.6" shape="square"/>
<pad name="PE13" x="20.23" y="-6.35" drill="0.6" shape="square"/>
<pad name="PA8" x="20.23" y="-3.81" drill="0.6" shape="square"/>
<pad name="PC8" x="20.23" y="-1.27" drill="0.6" shape="square"/>
<pad name="PD1" x="17.69" y="1.27" drill="0.6" shape="square"/>
<pad name="PD15" x="17.69" y="3.81" drill="0.6" shape="square"/>
<pad name="PD13" x="17.69" y="6.35" drill="0.6" shape="square"/>
<pad name="PD5" x="17.69" y="8.89" drill="0.6" shape="square"/>
<pad name="PD7" x="17.69" y="11.43" drill="0.6" shape="square"/>
<pad name="PB1" x="17.69" y="13.97" drill="0.6" shape="square"/>
<pad name="PB3" x="17.69" y="16.51" drill="0.6" shape="square"/>
<pad name="PB5" x="17.69" y="19.05" drill="0.6" shape="square"/>
<pad name="PB7" x="17.69" y="21.59" drill="0.6" shape="square"/>
<pad name="5V_0" x="17.69" y="24.13" drill="0.6" shape="square"/>
<pad name="GND_1" x="17.69" y="-24.13" drill="0.6" shape="square"/>
<pad name="PC4" x="17.69" y="-21.59" drill="0.6" shape="square"/>
<pad name="PB14" x="17.69" y="-19.05" drill="0.6" shape="square"/>
<pad name="PB12" x="17.69" y="-16.51" drill="0.6" shape="square"/>
<pad name="PD10" x="17.69" y="-13.97" drill="0.6" shape="square"/>
<pad name="PD8" x="17.69" y="-11.43" drill="0.6" shape="square"/>
<pad name="PE14" x="17.69" y="-8.89" drill="0.6" shape="square"/>
<pad name="PE12" x="17.69" y="-6.35" drill="0.6" shape="square"/>
<pad name="PC9" x="17.69" y="-3.81" drill="0.6" shape="square"/>
<pad name="PC7" x="17.69" y="-1.27" drill="0.6" shape="square"/>
<pad name="GND_3" x="11.5" y="-28" drill="0.6" shape="square"/>
<pad name="3V3_1" x="8.96" y="-28" drill="0.6" shape="square"/>
<pad name="PA2" x="6.42" y="-28" drill="0.6" shape="square"/>
<pad name="PA3" x="3.88" y="-28" drill="0.6" shape="square"/>
<pad name="PA7" x="-3.62" y="-28" drill="0.6" shape="square"/>
<pad name="PA6" x="-6.16" y="-28" drill="0.6" shape="square"/>
<pad name="PA5" x="-8.7" y="-28" drill="0.6" shape="square"/>
<pad name="PA4" x="-11.24" y="-28" drill="0.6" shape="square"/>
<pad name="GND_2" x="-17.5" y="-22.5" drill="0.6" shape="square"/>
<pad name="5V_2" x="-17.5" y="-19.96" drill="0.6" shape="square"/>
<pad name="PC1" x="-17.5" y="-17.42" drill="0.6" shape="square"/>
<pad name="PC2" x="-17.5" y="-14.88" drill="0.6" shape="square"/>
<pad name="SWC" x="-6.38" y="28" drill="0.6" shape="square"/>
<pad name="GND" x="-8.92" y="28" drill="0.6" shape="square"/>
<pad name="SWD" x="-11.46" y="28" drill="0.6" shape="square"/>
<pad name="5V_1" x="-14" y="28" drill="0.6" shape="square"/>
<text x="-22.86" y="35.56" size="1.27" layer="25">&gt;NAME</text>
<text x="-22.86" y="-36.83" size="1.27" layer="27">&gt;VALUE</text>
</package>
<package name="GPS">
<rectangle x1="-18" y1="-12.75" x2="18" y2="12.75" layer="21"/>
<hole x="16" y="10.75" drill="3"/>
<hole x="-16" y="10.75" drill="3"/>
<hole x="-16" y="-10.75" drill="3"/>
<hole x="16" y="-10.75" drill="3"/>
<pad name="TX" x="-16" y="1.27" drill="0.8" shape="square"/>
<pad name="RX" x="-16" y="-1.27" drill="0.8" shape="square"/>
<pad name="UCC" x="-16" y="-3.81" drill="0.8" shape="square"/>
<pad name="GND" x="-16" y="3.81" drill="0.8" shape="square"/>
<text x="-16.51" y="13.97" size="1.27" layer="25">&gt;NAME</text>
<text x="-16.51" y="-15.24" size="1.27" layer="27">&gt;VALUE</text>
<dimension x1="-18" y1="-12.75" x2="18" y2="-12.75" x3="0" y3="-19.2" textsize="1.27" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="ICU">
<pin name="PD1" x="7.62" y="0" length="middle"/>
<pin name="PD15" x="7.62" y="5.08" length="middle"/>
<pin name="PD13" x="7.62" y="10.16" length="middle"/>
<pin name="PD5" x="7.62" y="15.24" length="middle"/>
<pin name="PD7" x="7.62" y="20.32" length="middle"/>
<pin name="PB1" x="7.62" y="25.4" length="middle"/>
<pin name="PB3" x="7.62" y="30.48" length="middle"/>
<pin name="PB5" x="7.62" y="35.56" length="middle"/>
<pin name="PB7" x="7.62" y="40.64" length="middle"/>
<pin name="5V_0" x="7.62" y="45.72" length="middle"/>
<pin name="PC7" x="7.62" y="-5.08" length="middle"/>
<pin name="PC9" x="7.62" y="-10.16" length="middle"/>
<pin name="PE12" x="7.62" y="-15.24" length="middle"/>
<pin name="PE14" x="7.62" y="-20.32" length="middle"/>
<pin name="PD8" x="7.62" y="-25.4" length="middle"/>
<pin name="PD10" x="7.62" y="-30.48" length="middle"/>
<pin name="PB12" x="7.62" y="-35.56" length="middle"/>
<pin name="PB14" x="7.62" y="-40.64" length="middle"/>
<pin name="PC4" x="7.62" y="-45.72" length="middle"/>
<pin name="GND_1" x="7.62" y="-50.8" length="middle"/>
<pin name="PC8" x="43.18" y="-5.08" length="middle" rot="R180"/>
<pin name="PA8" x="43.18" y="-10.16" length="middle" rot="R180"/>
<pin name="PE13" x="43.18" y="-15.24" length="middle" rot="R180"/>
<pin name="PE15" x="43.18" y="-20.32" length="middle" rot="R180"/>
<pin name="PD9" x="43.18" y="-25.4" length="middle" rot="R180"/>
<pin name="PC5" x="43.18" y="-30.48" length="middle" rot="R180"/>
<pin name="PB13" x="43.18" y="-35.56" length="middle" rot="R180"/>
<pin name="PB15" x="43.18" y="-40.64" length="middle" rot="R180"/>
<pin name="PA1" x="43.18" y="-45.72" length="middle" rot="R180"/>
<pin name="3V3_0" x="43.18" y="-50.8" length="middle" rot="R180"/>
<pin name="PE7" x="43.18" y="0" length="middle" rot="R180"/>
<pin name="PD0" x="43.18" y="5.08" length="middle" rot="R180"/>
<pin name="PD14" x="43.18" y="10.16" length="middle" rot="R180"/>
<pin name="PD4" x="43.18" y="15.24" length="middle" rot="R180"/>
<pin name="PD11" x="43.18" y="20.32" length="middle" rot="R180"/>
<pin name="PB0" x="43.18" y="25.4" length="middle" rot="R180"/>
<pin name="PB2" x="43.18" y="30.48" length="middle" rot="R180"/>
<pin name="PB4" x="43.18" y="35.56" length="middle" rot="R180"/>
<pin name="PB6" x="43.18" y="40.64" length="middle" rot="R180"/>
<pin name="GND_0" x="43.18" y="45.72" length="middle" rot="R180"/>
<wire x1="12.7" y1="-53.34" x2="12.7" y2="48.26" width="0.254" layer="94"/>
<wire x1="12.7" y1="48.26" x2="38.1" y2="48.26" width="0.254" layer="94"/>
<wire x1="38.1" y1="48.26" x2="38.1" y2="-53.34" width="0.254" layer="94"/>
<wire x1="38.1" y1="-53.34" x2="12.7" y2="-53.34" width="0.254" layer="94"/>
<pin name="SWC" x="-22.86" y="53.34" length="middle" rot="R270"/>
<pin name="GND" x="-27.94" y="53.34" length="middle" rot="R270"/>
<pin name="SWD" x="-33.02" y="53.34" length="middle" rot="R270"/>
<pin name="5V_1" x="-38.1" y="53.34" length="middle" rot="R270"/>
<pin name="GND_2" x="-53.34" y="-50.8" length="middle"/>
<pin name="5V_2" x="-53.34" y="-45.72" length="middle"/>
<pin name="PC1" x="-53.34" y="-40.64" length="middle"/>
<pin name="PC2" x="-53.34" y="-35.56" length="middle"/>
<pin name="PA7" x="-22.86" y="-58.42" length="middle" rot="R90"/>
<pin name="PA6" x="-27.94" y="-58.42" length="middle" rot="R90"/>
<pin name="PA5" x="-33.02" y="-58.42" length="middle" rot="R90"/>
<pin name="PA4" x="-38.1" y="-58.42" length="middle" rot="R90"/>
<pin name="PA3" x="-15.24" y="-58.42" length="middle" rot="R90"/>
<pin name="PA2" x="-10.16" y="-58.42" length="middle" rot="R90"/>
<pin name="3V3_1" x="-5.08" y="-58.42" length="middle" rot="R90"/>
<pin name="GND_3" x="0" y="-58.42" length="middle" rot="R90"/>
<wire x1="12.7" y1="48.26" x2="-48.26" y2="48.26" width="0.254" layer="94"/>
<wire x1="-48.26" y1="48.26" x2="-48.26" y2="-53.34" width="0.254" layer="94"/>
<wire x1="-48.26" y1="-53.34" x2="12.7" y2="-53.34" width="0.254" layer="94"/>
<text x="-48.26" y="60.96" size="1.778" layer="95">&gt;NAME</text>
<text x="-45.72" y="-68.58" size="1.778" layer="96">&gt;VALUE</text>
</symbol>
<symbol name="GPS">
<pin name="TX" x="-12.7" y="2.54" length="middle"/>
<pin name="RX" x="-12.7" y="-2.54" length="middle"/>
<pin name="GND" x="-12.7" y="7.62" length="middle"/>
<pin name="UCC" x="-12.7" y="-7.62" length="middle"/>
<wire x1="-7.62" y1="-10.16" x2="7.62" y2="-10.16" width="0.254" layer="94"/>
<wire x1="7.62" y1="-10.16" x2="7.62" y2="10.16" width="0.254" layer="94"/>
<wire x1="7.62" y1="10.16" x2="-7.62" y2="10.16" width="0.254" layer="94"/>
<wire x1="-7.62" y1="10.16" x2="-7.62" y2="-10.16" width="0.254" layer="94"/>
<text x="-7.62" y="12.7" size="1.27" layer="95">&gt;NAME</text>
<text x="-7.62" y="-12.7" size="1.27" layer="96">&gt;VALUE</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="ICU">
<gates>
<gate name="G$1" symbol="ICU" x="0" y="0"/>
</gates>
<devices>
<device name="" package="ICU">
<connects>
<connect gate="G$1" pin="3V3_0" pad="3V3_0"/>
<connect gate="G$1" pin="3V3_1" pad="3V3_1"/>
<connect gate="G$1" pin="5V_0" pad="5V_0"/>
<connect gate="G$1" pin="5V_1" pad="5V_1"/>
<connect gate="G$1" pin="5V_2" pad="5V_2"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="GND_0" pad="GND_0"/>
<connect gate="G$1" pin="GND_1" pad="GND_1"/>
<connect gate="G$1" pin="GND_2" pad="GND_2"/>
<connect gate="G$1" pin="GND_3" pad="GND_3"/>
<connect gate="G$1" pin="PA1" pad="PA1"/>
<connect gate="G$1" pin="PA2" pad="PA2"/>
<connect gate="G$1" pin="PA3" pad="PA3"/>
<connect gate="G$1" pin="PA4" pad="PA4"/>
<connect gate="G$1" pin="PA5" pad="PA5"/>
<connect gate="G$1" pin="PA6" pad="PA6"/>
<connect gate="G$1" pin="PA7" pad="PA7"/>
<connect gate="G$1" pin="PA8" pad="PA8"/>
<connect gate="G$1" pin="PB0" pad="PB0"/>
<connect gate="G$1" pin="PB1" pad="PB1"/>
<connect gate="G$1" pin="PB12" pad="PB12"/>
<connect gate="G$1" pin="PB13" pad="PB13"/>
<connect gate="G$1" pin="PB14" pad="PB14"/>
<connect gate="G$1" pin="PB15" pad="PB15"/>
<connect gate="G$1" pin="PB2" pad="PB2"/>
<connect gate="G$1" pin="PB3" pad="PB3"/>
<connect gate="G$1" pin="PB4" pad="PB4"/>
<connect gate="G$1" pin="PB5" pad="PB5"/>
<connect gate="G$1" pin="PB6" pad="PB6"/>
<connect gate="G$1" pin="PB7" pad="PB7"/>
<connect gate="G$1" pin="PC1" pad="PC1"/>
<connect gate="G$1" pin="PC2" pad="PC2"/>
<connect gate="G$1" pin="PC4" pad="PC4"/>
<connect gate="G$1" pin="PC5" pad="PC5"/>
<connect gate="G$1" pin="PC7" pad="PC7"/>
<connect gate="G$1" pin="PC8" pad="PC8"/>
<connect gate="G$1" pin="PC9" pad="PC9"/>
<connect gate="G$1" pin="PD0" pad="PD0"/>
<connect gate="G$1" pin="PD1" pad="PD1"/>
<connect gate="G$1" pin="PD10" pad="PD10"/>
<connect gate="G$1" pin="PD11" pad="PD11"/>
<connect gate="G$1" pin="PD13" pad="PD13"/>
<connect gate="G$1" pin="PD14" pad="PD14"/>
<connect gate="G$1" pin="PD15" pad="PD15"/>
<connect gate="G$1" pin="PD4" pad="PD4"/>
<connect gate="G$1" pin="PD5" pad="PD5"/>
<connect gate="G$1" pin="PD7" pad="PD7"/>
<connect gate="G$1" pin="PD8" pad="PD8"/>
<connect gate="G$1" pin="PD9" pad="PD9"/>
<connect gate="G$1" pin="PE12" pad="PE12"/>
<connect gate="G$1" pin="PE13" pad="PE13"/>
<connect gate="G$1" pin="PE14" pad="PE14"/>
<connect gate="G$1" pin="PE15" pad="PE15"/>
<connect gate="G$1" pin="PE7" pad="PE7"/>
<connect gate="G$1" pin="SWC" pad="SWC"/>
<connect gate="G$1" pin="SWD" pad="SWD"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="GPS">
<gates>
<gate name="G$1" symbol="GPS" x="0" y="0"/>
</gates>
<devices>
<device name="" package="GPS">
<connects>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="RX" pad="RX"/>
<connect gate="G$1" pin="TX" pad="TX"/>
<connect gate="G$1" pin="UCC" pad="UCC"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="pinhead" urn="urn:adsk.eagle:library:325">
<description>&lt;b&gt;Pin Header Connectors&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="2X10" urn="urn:adsk.eagle:footprint:22268/1" library_version="3">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-12.7" y1="-1.905" x2="-12.065" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-10.795" y1="-2.54" x2="-10.16" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="-1.905" x2="-9.525" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="-2.54" x2="-7.62" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="-1.905" x2="-6.985" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="-2.54" x2="-5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-1.905" x2="-4.445" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-2.54" x2="-2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-1.905" x2="-1.905" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-2.54" x2="0" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="0" y1="-1.905" x2="0.635" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-2.54" x2="2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="-1.905" x2="-12.7" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="1.905" x2="-12.065" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-12.065" y1="2.54" x2="-10.795" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-10.795" y1="2.54" x2="-10.16" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="1.905" x2="-9.525" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-9.525" y1="2.54" x2="-8.255" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="2.54" x2="-7.62" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="1.905" x2="-6.985" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="2.54" x2="-5.715" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="2.54" x2="-5.08" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="1.905" x2="-4.445" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="2.54" x2="-3.175" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="2.54" x2="-2.54" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="1.905" x2="-1.905" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="2.54" x2="-0.635" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="2.54" x2="0" y2="1.905" width="0.1524" layer="21"/>
<wire x1="0" y1="1.905" x2="0.635" y2="2.54" width="0.1524" layer="21"/>
<wire x1="0.635" y1="2.54" x2="1.905" y2="2.54" width="0.1524" layer="21"/>
<wire x1="1.905" y1="2.54" x2="2.54" y2="1.905" width="0.1524" layer="21"/>
<wire x1="2.54" y1="1.905" x2="3.175" y2="2.54" width="0.1524" layer="21"/>
<wire x1="3.175" y1="2.54" x2="4.445" y2="2.54" width="0.1524" layer="21"/>
<wire x1="4.445" y1="2.54" x2="5.08" y2="1.905" width="0.1524" layer="21"/>
<wire x1="5.08" y1="1.905" x2="5.715" y2="2.54" width="0.1524" layer="21"/>
<wire x1="5.715" y1="2.54" x2="6.985" y2="2.54" width="0.1524" layer="21"/>
<wire x1="6.985" y1="2.54" x2="7.62" y2="1.905" width="0.1524" layer="21"/>
<wire x1="7.62" y1="1.905" x2="8.255" y2="2.54" width="0.1524" layer="21"/>
<wire x1="8.255" y1="2.54" x2="9.525" y2="2.54" width="0.1524" layer="21"/>
<wire x1="9.525" y1="2.54" x2="10.16" y2="1.905" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-1.905" x2="9.525" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="7.62" y1="-1.905" x2="8.255" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="7.62" y1="-1.905" x2="6.985" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-1.905" x2="5.715" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-1.905" x2="4.445" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="3.175" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="1.905" x2="-10.16" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="1.905" x2="-7.62" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="1.905" x2="-5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="1.905" x2="-2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="0" y1="1.905" x2="0" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="2.54" y1="1.905" x2="2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="5.08" y1="1.905" x2="5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="7.62" y1="1.905" x2="7.62" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="10.16" y1="1.905" x2="10.16" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="8.255" y1="-2.54" x2="9.525" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="5.715" y1="-2.54" x2="6.985" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-2.54" x2="4.445" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-2.54" x2="1.905" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-2.54" x2="-0.635" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="-2.54" x2="-3.175" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="-2.54" x2="-5.715" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-9.525" y1="-2.54" x2="-8.255" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-12.065" y1="-2.54" x2="-10.795" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="10.16" y1="1.905" x2="10.795" y2="2.54" width="0.1524" layer="21"/>
<wire x1="10.795" y1="2.54" x2="12.065" y2="2.54" width="0.1524" layer="21"/>
<wire x1="12.065" y1="2.54" x2="12.7" y2="1.905" width="0.1524" layer="21"/>
<wire x1="12.7" y1="-1.905" x2="12.065" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-1.905" x2="10.795" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="12.7" y1="1.905" x2="12.7" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="10.795" y1="-2.54" x2="12.065" y2="-2.54" width="0.1524" layer="21"/>
<pad name="1" x="-11.43" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="2" x="-11.43" y="1.27" drill="1.016" shape="octagon"/>
<pad name="3" x="-8.89" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="4" x="-8.89" y="1.27" drill="1.016" shape="octagon"/>
<pad name="5" x="-6.35" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="6" x="-6.35" y="1.27" drill="1.016" shape="octagon"/>
<pad name="7" x="-3.81" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="8" x="-3.81" y="1.27" drill="1.016" shape="octagon"/>
<pad name="9" x="-1.27" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="10" x="-1.27" y="1.27" drill="1.016" shape="octagon"/>
<pad name="11" x="1.27" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="12" x="1.27" y="1.27" drill="1.016" shape="octagon"/>
<pad name="13" x="3.81" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="14" x="3.81" y="1.27" drill="1.016" shape="octagon"/>
<pad name="15" x="6.35" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="16" x="6.35" y="1.27" drill="1.016" shape="octagon"/>
<pad name="17" x="8.89" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="18" x="8.89" y="1.27" drill="1.016" shape="octagon"/>
<pad name="19" x="11.43" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="20" x="11.43" y="1.27" drill="1.016" shape="octagon"/>
<text x="-12.7" y="3.175" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-12.7" y="-4.445" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-11.684" y1="-1.524" x2="-11.176" y2="-1.016" layer="51"/>
<rectangle x1="-11.684" y1="1.016" x2="-11.176" y2="1.524" layer="51"/>
<rectangle x1="-9.144" y1="1.016" x2="-8.636" y2="1.524" layer="51"/>
<rectangle x1="-9.144" y1="-1.524" x2="-8.636" y2="-1.016" layer="51"/>
<rectangle x1="-6.604" y1="1.016" x2="-6.096" y2="1.524" layer="51"/>
<rectangle x1="-6.604" y1="-1.524" x2="-6.096" y2="-1.016" layer="51"/>
<rectangle x1="-4.064" y1="1.016" x2="-3.556" y2="1.524" layer="51"/>
<rectangle x1="-1.524" y1="1.016" x2="-1.016" y2="1.524" layer="51"/>
<rectangle x1="1.016" y1="1.016" x2="1.524" y2="1.524" layer="51"/>
<rectangle x1="-4.064" y1="-1.524" x2="-3.556" y2="-1.016" layer="51"/>
<rectangle x1="-1.524" y1="-1.524" x2="-1.016" y2="-1.016" layer="51"/>
<rectangle x1="1.016" y1="-1.524" x2="1.524" y2="-1.016" layer="51"/>
<rectangle x1="3.556" y1="1.016" x2="4.064" y2="1.524" layer="51"/>
<rectangle x1="3.556" y1="-1.524" x2="4.064" y2="-1.016" layer="51"/>
<rectangle x1="6.096" y1="1.016" x2="6.604" y2="1.524" layer="51"/>
<rectangle x1="6.096" y1="-1.524" x2="6.604" y2="-1.016" layer="51"/>
<rectangle x1="8.636" y1="1.016" x2="9.144" y2="1.524" layer="51"/>
<rectangle x1="8.636" y1="-1.524" x2="9.144" y2="-1.016" layer="51"/>
<rectangle x1="11.176" y1="1.016" x2="11.684" y2="1.524" layer="51"/>
<rectangle x1="11.176" y1="-1.524" x2="11.684" y2="-1.016" layer="51"/>
</package>
<package name="2X10/90" urn="urn:adsk.eagle:footprint:22269/1" library_version="3">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-12.7" y1="-1.905" x2="-10.16" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="-1.905" x2="-10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="0.635" x2="-12.7" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="0.635" x2="-12.7" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-11.43" y1="6.985" x2="-11.43" y2="1.27" width="0.762" layer="21"/>
<wire x1="-10.16" y1="-1.905" x2="-7.62" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="-1.905" x2="-7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="0.635" x2="-10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="6.985" x2="-8.89" y2="1.27" width="0.762" layer="21"/>
<wire x1="-7.62" y1="-1.905" x2="-5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-1.905" x2="-5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="0.635" x2="-7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="6.985" x2="-6.35" y2="1.27" width="0.762" layer="21"/>
<wire x1="-5.08" y1="-1.905" x2="-2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-1.905" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="0.635" x2="-5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="6.985" x2="-3.81" y2="1.27" width="0.762" layer="21"/>
<wire x1="-2.54" y1="-1.905" x2="0" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="0" y1="-1.905" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="6.985" x2="-1.27" y2="1.27" width="0.762" layer="21"/>
<wire x1="0" y1="-1.905" x2="2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="0.635" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="6.985" x2="1.27" y2="1.27" width="0.762" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-1.905" x2="5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="0.635" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="3.81" y1="6.985" x2="3.81" y2="1.27" width="0.762" layer="21"/>
<wire x1="5.08" y1="-1.905" x2="7.62" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="7.62" y1="-1.905" x2="7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="7.62" y1="0.635" x2="5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="6.35" y1="6.985" x2="6.35" y2="1.27" width="0.762" layer="21"/>
<wire x1="7.62" y1="-1.905" x2="10.16" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-1.905" x2="10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="10.16" y1="0.635" x2="7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="8.89" y1="6.985" x2="8.89" y2="1.27" width="0.762" layer="21"/>
<wire x1="10.16" y1="-1.905" x2="12.7" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="12.7" y1="-1.905" x2="12.7" y2="0.635" width="0.1524" layer="21"/>
<wire x1="12.7" y1="0.635" x2="10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="11.43" y1="6.985" x2="11.43" y2="1.27" width="0.762" layer="21"/>
<pad name="2" x="-11.43" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="4" x="-8.89" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="6" x="-6.35" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="8" x="-3.81" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="10" x="-1.27" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="12" x="1.27" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="14" x="3.81" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="16" x="6.35" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="18" x="8.89" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="20" x="11.43" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="1" x="-11.43" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="3" x="-8.89" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="5" x="-6.35" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="7" x="-3.81" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="9" x="-1.27" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="11" x="1.27" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="13" x="3.81" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="15" x="6.35" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="17" x="8.89" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="19" x="11.43" y="-6.35" drill="1.016" shape="octagon"/>
<text x="-13.335" y="-3.81" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="14.605" y="-4.445" size="1.27" layer="27" rot="R90">&gt;VALUE</text>
<rectangle x1="-11.811" y1="0.635" x2="-11.049" y2="1.143" layer="21"/>
<rectangle x1="-9.271" y1="0.635" x2="-8.509" y2="1.143" layer="21"/>
<rectangle x1="-6.731" y1="0.635" x2="-5.969" y2="1.143" layer="21"/>
<rectangle x1="-4.191" y1="0.635" x2="-3.429" y2="1.143" layer="21"/>
<rectangle x1="-1.651" y1="0.635" x2="-0.889" y2="1.143" layer="21"/>
<rectangle x1="0.889" y1="0.635" x2="1.651" y2="1.143" layer="21"/>
<rectangle x1="3.429" y1="0.635" x2="4.191" y2="1.143" layer="21"/>
<rectangle x1="5.969" y1="0.635" x2="6.731" y2="1.143" layer="21"/>
<rectangle x1="8.509" y1="0.635" x2="9.271" y2="1.143" layer="21"/>
<rectangle x1="11.049" y1="0.635" x2="11.811" y2="1.143" layer="21"/>
<rectangle x1="-11.811" y1="-2.921" x2="-11.049" y2="-1.905" layer="21"/>
<rectangle x1="-9.271" y1="-2.921" x2="-8.509" y2="-1.905" layer="21"/>
<rectangle x1="-11.811" y1="-5.461" x2="-11.049" y2="-4.699" layer="21"/>
<rectangle x1="-11.811" y1="-4.699" x2="-11.049" y2="-2.921" layer="51"/>
<rectangle x1="-9.271" y1="-4.699" x2="-8.509" y2="-2.921" layer="51"/>
<rectangle x1="-9.271" y1="-5.461" x2="-8.509" y2="-4.699" layer="21"/>
<rectangle x1="-6.731" y1="-2.921" x2="-5.969" y2="-1.905" layer="21"/>
<rectangle x1="-4.191" y1="-2.921" x2="-3.429" y2="-1.905" layer="21"/>
<rectangle x1="-6.731" y1="-5.461" x2="-5.969" y2="-4.699" layer="21"/>
<rectangle x1="-6.731" y1="-4.699" x2="-5.969" y2="-2.921" layer="51"/>
<rectangle x1="-4.191" y1="-4.699" x2="-3.429" y2="-2.921" layer="51"/>
<rectangle x1="-4.191" y1="-5.461" x2="-3.429" y2="-4.699" layer="21"/>
<rectangle x1="-1.651" y1="-2.921" x2="-0.889" y2="-1.905" layer="21"/>
<rectangle x1="0.889" y1="-2.921" x2="1.651" y2="-1.905" layer="21"/>
<rectangle x1="-1.651" y1="-5.461" x2="-0.889" y2="-4.699" layer="21"/>
<rectangle x1="-1.651" y1="-4.699" x2="-0.889" y2="-2.921" layer="51"/>
<rectangle x1="0.889" y1="-4.699" x2="1.651" y2="-2.921" layer="51"/>
<rectangle x1="0.889" y1="-5.461" x2="1.651" y2="-4.699" layer="21"/>
<rectangle x1="3.429" y1="-2.921" x2="4.191" y2="-1.905" layer="21"/>
<rectangle x1="5.969" y1="-2.921" x2="6.731" y2="-1.905" layer="21"/>
<rectangle x1="3.429" y1="-5.461" x2="4.191" y2="-4.699" layer="21"/>
<rectangle x1="3.429" y1="-4.699" x2="4.191" y2="-2.921" layer="51"/>
<rectangle x1="5.969" y1="-4.699" x2="6.731" y2="-2.921" layer="51"/>
<rectangle x1="5.969" y1="-5.461" x2="6.731" y2="-4.699" layer="21"/>
<rectangle x1="8.509" y1="-2.921" x2="9.271" y2="-1.905" layer="21"/>
<rectangle x1="11.049" y1="-2.921" x2="11.811" y2="-1.905" layer="21"/>
<rectangle x1="8.509" y1="-5.461" x2="9.271" y2="-4.699" layer="21"/>
<rectangle x1="8.509" y1="-4.699" x2="9.271" y2="-2.921" layer="51"/>
<rectangle x1="11.049" y1="-4.699" x2="11.811" y2="-2.921" layer="51"/>
<rectangle x1="11.049" y1="-5.461" x2="11.811" y2="-4.699" layer="21"/>
</package>
</packages>
<packages3d>
<package3d name="2X10" urn="urn:adsk.eagle:package:22405/2" type="model" library_version="3">
<description>PIN HEADER</description>
<packageinstances>
<packageinstance name="2X10"/>
</packageinstances>
</package3d>
<package3d name="2X10/90" urn="urn:adsk.eagle:package:22411/2" type="model" library_version="3">
<description>PIN HEADER</description>
<packageinstances>
<packageinstance name="2X10/90"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="PINH2X10" urn="urn:adsk.eagle:symbol:22266/1" library_version="3">
<wire x1="-6.35" y1="-15.24" x2="8.89" y2="-15.24" width="0.4064" layer="94"/>
<wire x1="8.89" y1="-15.24" x2="8.89" y2="12.7" width="0.4064" layer="94"/>
<wire x1="8.89" y1="12.7" x2="-6.35" y2="12.7" width="0.4064" layer="94"/>
<wire x1="-6.35" y1="12.7" x2="-6.35" y2="-15.24" width="0.4064" layer="94"/>
<text x="-6.35" y="13.335" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.35" y="-17.78" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="-2.54" y="10.16" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="2" x="5.08" y="10.16" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="3" x="-2.54" y="7.62" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="4" x="5.08" y="7.62" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="5" x="-2.54" y="5.08" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="6" x="5.08" y="5.08" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="7" x="-2.54" y="2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="8" x="5.08" y="2.54" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="9" x="-2.54" y="0" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="10" x="5.08" y="0" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="11" x="-2.54" y="-2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="12" x="5.08" y="-2.54" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="13" x="-2.54" y="-5.08" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="14" x="5.08" y="-5.08" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="15" x="-2.54" y="-7.62" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="16" x="5.08" y="-7.62" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="17" x="-2.54" y="-10.16" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="18" x="5.08" y="-10.16" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="19" x="-2.54" y="-12.7" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="20" x="5.08" y="-12.7" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="PINHD-2X10" urn="urn:adsk.eagle:component:22511/3" prefix="JP" uservalue="yes" library_version="3">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="A" symbol="PINH2X10" x="0" y="0"/>
</gates>
<devices>
<device name="" package="2X10">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="10" pad="10"/>
<connect gate="A" pin="11" pad="11"/>
<connect gate="A" pin="12" pad="12"/>
<connect gate="A" pin="13" pad="13"/>
<connect gate="A" pin="14" pad="14"/>
<connect gate="A" pin="15" pad="15"/>
<connect gate="A" pin="16" pad="16"/>
<connect gate="A" pin="17" pad="17"/>
<connect gate="A" pin="18" pad="18"/>
<connect gate="A" pin="19" pad="19"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="20" pad="20"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
<connect gate="A" pin="7" pad="7"/>
<connect gate="A" pin="8" pad="8"/>
<connect gate="A" pin="9" pad="9"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:22405/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="/90" package="2X10/90">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="10" pad="10"/>
<connect gate="A" pin="11" pad="11"/>
<connect gate="A" pin="12" pad="12"/>
<connect gate="A" pin="13" pad="13"/>
<connect gate="A" pin="14" pad="14"/>
<connect gate="A" pin="15" pad="15"/>
<connect gate="A" pin="16" pad="16"/>
<connect gate="A" pin="17" pad="17"/>
<connect gate="A" pin="18" pad="18"/>
<connect gate="A" pin="19" pad="19"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="20" pad="20"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
<connect gate="A" pin="7" pad="7"/>
<connect gate="A" pin="8" pad="8"/>
<connect gate="A" pin="9" pad="9"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:22411/2"/>
</package3dinstances>
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
<library name="con-jst-eh">
<description>&lt;b&gt;JST Connectors&lt;/b&gt; - EH 2.5 MM Series&lt;p&gt;
&lt;p&gt;THIS LIBRARY IS PROVIDED AS IS AND WITHOUT WARRANTY OF ANY KIND, EXPRESSED OR IMPLIED.&lt;br&gt;
USE AT YOUR OWN RISK!&lt;p&gt;
&lt;author&gt;Copyright (C) 2016, Bob Starr&lt;br&gt; http://www.bobstarr.net&lt;br&gt;&lt;/author&gt;</description>
<packages>
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
</packages>
<symbols>
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
</symbols>
<devicesets>
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
</devicesets>
</library>
<library name="ebyte-radio">
<packages>
<package name="E22-400M22S">
<description>EBYTE E22400M22S radio module

Datasheet and info: http://www.ebyte.com/en/product-view-news.aspx?id=436</description>
<wire x1="-10" y1="7" x2="-10" y2="-7" width="0.127" layer="21"/>
<wire x1="10" y1="7" x2="10" y2="-7" width="0.127" layer="21"/>
<smd name="P$1" x="-9" y="-6.97" dx="1.6764" dy="0.8128" layer="1" rot="R90"/>
<smd name="P$2" x="-7.73" y="-6.97" dx="1.6764" dy="0.8128" layer="1" rot="R90"/>
<smd name="P$3" x="-6.46" y="-6.97" dx="1.6764" dy="0.8128" layer="1" rot="R90"/>
<smd name="P$4" x="-0.89" y="-6.97" dx="1.6764" dy="0.8128" layer="1" rot="R90"/>
<smd name="P$5" x="0.38" y="-6.97" dx="1.6764" dy="0.8128" layer="1" rot="R90"/>
<smd name="P$6" x="1.65" y="-6.97" dx="1.6764" dy="0.8128" layer="1" rot="R90"/>
<smd name="P$7" x="2.92" y="-6.97" dx="1.6764" dy="0.8128" layer="1" rot="R90"/>
<smd name="P$8" x="4.19" y="-6.97" dx="1.6764" dy="0.8128" layer="1" rot="R90"/>
<smd name="P$9" x="5.46" y="-6.97" dx="1.6764" dy="0.8128" layer="1" rot="R90"/>
<smd name="P$10" x="6.73" y="-6.97" dx="1.6764" dy="0.8128" layer="1" rot="R90"/>
<smd name="P$11" x="8" y="-6.97" dx="1.6764" dy="0.8128" layer="1" rot="R90"/>
<circle x="-7.62" y="3.81" radius="1.27" width="0.127" layer="51"/>
<circle x="-7.62" y="3.81" radius="0.2" width="0.127" layer="51"/>
<wire x1="8.89" y1="5.08" x2="-5.08" y2="5.08" width="0.127" layer="51"/>
<wire x1="-5.08" y1="5.08" x2="-5.08" y2="1.27" width="0.127" layer="51"/>
<wire x1="-5.08" y1="1.27" x2="-8.89" y2="1.27" width="0.127" layer="51"/>
<wire x1="-8.89" y1="1.27" x2="-8.89" y2="-5.08" width="0.127" layer="51"/>
<wire x1="-8.89" y1="-5.08" x2="8.89" y2="-5.08" width="0.127" layer="51"/>
<wire x1="8.89" y1="-5.08" x2="8.89" y2="5.08" width="0.127" layer="51"/>
<text x="-7.62" y="-1.27" size="1.27" layer="25">&gt;Name</text>
<text x="-7.62" y="-3.81" size="1.27" layer="27">&gt;Value</text>
<smd name="P$12" x="8" y="7" dx="1.6764" dy="0.8128" layer="1" rot="R90"/>
<smd name="P$13" x="6.73" y="7" dx="1.6764" dy="0.8128" layer="1" rot="R90"/>
<smd name="P$14" x="5.46" y="7" dx="1.6764" dy="0.8128" layer="1" rot="R90"/>
<smd name="P$15" x="4.19" y="7" dx="1.6764" dy="0.8128" layer="1" rot="R90"/>
<smd name="P$16" x="2.92" y="7" dx="1.6764" dy="0.8128" layer="1" rot="R90"/>
<smd name="P$17" x="1.65" y="7" dx="1.6764" dy="0.8128" layer="1" rot="R90"/>
<smd name="P$18" x="0.38" y="7" dx="1.6764" dy="0.8128" layer="1" rot="R90"/>
<smd name="P$19" x="-0.89" y="7" dx="1.6764" dy="0.8128" layer="1" rot="R90"/>
<smd name="P$20" x="-6.46" y="7" dx="1.6764" dy="0.8128" layer="1" rot="R90"/>
<smd name="P$21" x="-7.73" y="7" dx="1.6764" dy="0.8128" layer="1" rot="R90"/>
<smd name="P$22" x="-9" y="7" dx="1.6764" dy="0.8128" layer="1" rot="R90"/>
<wire x1="-5" y1="7" x2="-2" y2="7" width="0.127" layer="21"/>
<wire x1="-5" y1="-7" x2="-2" y2="-7" width="0.127" layer="21"/>
<wire x1="10" y1="7" x2="9" y2="7" width="0.127" layer="21"/>
<wire x1="10" y1="-7" x2="9" y2="-7" width="0.127" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="E22-400M22S">
<description>EBYTE E22400M22S radio module

Datasheet and info: http://www.ebyte.com/en/product-view-news.aspx?id=436</description>
<pin name="VCC" x="-2.54" y="-25.4" length="middle" direction="pwr" rot="R90"/>
<pin name="GND" x="2.54" y="-25.4" length="middle" direction="sup" rot="R90"/>
<pin name="ANT" x="-17.78" y="-15.24" length="middle" direction="out"/>
<pin name="TXEN" x="17.78" y="-15.24" length="middle" direction="in" rot="R180"/>
<pin name="RXEN" x="17.78" y="-10.16" length="middle" direction="in" rot="R180"/>
<pin name="MISO" x="17.78" y="0" length="middle" direction="out" rot="R180"/>
<pin name="BUSY" x="-17.78" y="15.24" length="middle" direction="out"/>
<pin name="DIO1" x="-17.78" y="10.16" length="middle"/>
<pin name="DIO2" x="-17.78" y="5.08" length="middle"/>
<pin name="NSS" x="17.78" y="15.24" length="middle" direction="in" rot="R180"/>
<pin name="SCK" x="17.78" y="10.16" length="middle" direction="in" rot="R180"/>
<pin name="MOSI" x="17.78" y="5.08" length="middle" direction="in" rot="R180"/>
<wire x1="-12.7" y1="20.32" x2="12.7" y2="20.32" width="0.254" layer="94"/>
<wire x1="12.7" y1="20.32" x2="12.7" y2="-20.32" width="0.254" layer="94"/>
<wire x1="12.7" y1="-20.32" x2="-12.7" y2="-20.32" width="0.254" layer="94"/>
<wire x1="-12.7" y1="-20.32" x2="-12.7" y2="20.32" width="0.254" layer="94"/>
<text x="-12.7" y="25.4" size="1.27" layer="95">&gt;Name</text>
<text x="-12.7" y="22.86" size="1.27" layer="96">&gt;Value</text>
<pin name="NRST" x="-17.78" y="-5.08" length="middle" direction="in"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="E22-400M22S">
<description>EBYTE E22400M22S radio module

Datasheet and info: http://www.ebyte.com/en/product-view-news.aspx?id=436</description>
<gates>
<gate name="G$1" symbol="E22-400M22S" x="0" y="0"/>
</gates>
<devices>
<device name="" package="E22-400M22S">
<connects>
<connect gate="G$1" pin="ANT" pad="P$21"/>
<connect gate="G$1" pin="BUSY" pad="P$14"/>
<connect gate="G$1" pin="DIO1" pad="P$13"/>
<connect gate="G$1" pin="DIO2" pad="P$8"/>
<connect gate="G$1" pin="GND" pad="P$1 P$2 P$3 P$4 P$5 P$10 P$11 P$12 P$20 P$22"/>
<connect gate="G$1" pin="MISO" pad="P$16"/>
<connect gate="G$1" pin="MOSI" pad="P$17"/>
<connect gate="G$1" pin="NRST" pad="P$15"/>
<connect gate="G$1" pin="NSS" pad="P$19"/>
<connect gate="G$1" pin="RXEN" pad="P$6"/>
<connect gate="G$1" pin="SCK" pad="P$18"/>
<connect gate="G$1" pin="TXEN" pad="P$7"/>
<connect gate="G$1" pin="VCC" pad="P$9"/>
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
<part name="IRIDIUM" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-2X10" device="" package3d_urn="urn:adsk.eagle:package:22405/2"/>
<part name="GND1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND2" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND3" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="U$2" library="MCP2551" deviceset="MCP2551" device=""/>
<part name="GND5" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="R1" library="ngspice-simulation" library_urn="urn:adsk.eagle:library:527439" deviceset="R" device=""/>
<part name="GND6" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="P1" library="con-jst-eh" deviceset="B5B-EH-A" device=""/>
<part name="GND7" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="U$3" library="ebyte-radio" deviceset="E22-400M22S" device=""/>
<part name="R2" library="ngspice-simulation" library_urn="urn:adsk.eagle:library:527439" deviceset="R" device=""/>
<part name="U$4" library="bluepill" deviceset="ICU" device=""/>
<part name="U$1" library="bluepill" deviceset="GPS" device=""/>
<part name="GND4" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND9" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="IRIDIUM" gate="A" x="73.66" y="17.78" smashed="yes">
<attribute name="NAME" x="67.31" y="31.115" size="1.778" layer="95"/>
<attribute name="VALUE" x="67.31" y="0" size="1.778" layer="96"/>
</instance>
<instance part="GND1" gate="1" x="76.2" y="45.72" smashed="yes">
<attribute name="VALUE" x="73.66" y="43.18" size="1.778" layer="96"/>
</instance>
<instance part="GND2" gate="1" x="96.52" y="17.78" smashed="yes">
<attribute name="VALUE" x="93.98" y="15.24" size="1.778" layer="96"/>
</instance>
<instance part="GND3" gate="1" x="50.8" y="7.62" smashed="yes">
<attribute name="VALUE" x="48.26" y="5.08" size="1.778" layer="96"/>
</instance>
<instance part="U$2" gate="G$1" x="5.08" y="35.56" smashed="yes" rot="R270"/>
<instance part="GND5" gate="1" x="7.62" y="58.42" smashed="yes" rot="R90">
<attribute name="VALUE" x="10.16" y="55.88" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="R1" gate="G$1" x="7.62" y="5.08" smashed="yes" rot="R270">
<attribute name="NAME" x="10.16" y="7.62" size="1.778" layer="95" rot="R270"/>
<attribute name="VALUE" x="3.81" y="7.62" size="1.778" layer="96" rot="R270"/>
</instance>
<instance part="GND6" gate="1" x="7.62" y="-5.08" smashed="yes">
<attribute name="VALUE" x="5.08" y="-7.62" size="1.778" layer="96"/>
</instance>
<instance part="P1" gate="G$1" x="55.88" y="-58.42" smashed="yes" rot="R180">
<attribute name="NAME" x="57.15" y="-66.675" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="57.15" y="-48.26" size="1.778" layer="95" rot="R180"/>
</instance>
<instance part="GND7" gate="1" x="66.04" y="-68.58" smashed="yes">
<attribute name="VALUE" x="63.5" y="-71.12" size="1.778" layer="96"/>
</instance>
<instance part="U$3" gate="G$1" x="-96.52" y="132.08" smashed="yes">
<attribute name="NAME" x="-109.22" y="157.48" size="1.27" layer="95"/>
<attribute name="VALUE" x="-109.22" y="154.94" size="1.27" layer="96"/>
</instance>
<instance part="R2" gate="G$1" x="-124.46" y="109.22" smashed="yes" rot="R270">
<attribute name="NAME" x="-121.92" y="111.76" size="1.778" layer="95" rot="R270"/>
<attribute name="VALUE" x="-128.27" y="111.76" size="1.778" layer="96" rot="R270"/>
</instance>
<instance part="U$4" gate="G$1" x="5.08" y="114.3" smashed="yes" rot="R270">
<attribute name="NAME" x="66.04" y="162.56" size="1.778" layer="95" rot="R270"/>
<attribute name="VALUE" x="-63.5" y="160.02" size="1.778" layer="96" rot="R270"/>
</instance>
<instance part="U$1" gate="G$1" x="-88.9" y="63.5" smashed="yes" rot="R180">
<attribute name="NAME" x="-81.28" y="50.8" size="1.27" layer="95" rot="R180"/>
<attribute name="VALUE" x="-81.28" y="76.2" size="1.27" layer="96" rot="R180"/>
</instance>
<instance part="GND4" gate="1" x="-66.04" y="50.8" smashed="yes">
<attribute name="VALUE" x="-68.58" y="48.26" size="1.778" layer="96"/>
</instance>
<instance part="GND9" gate="1" x="-93.98" y="96.52" smashed="yes">
<attribute name="VALUE" x="-96.52" y="93.98" size="1.778" layer="96"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="5V_ICU" class="0">
<segment>
<pinref part="IRIDIUM" gate="A" pin="1"/>
<wire x1="71.12" y1="27.94" x2="66.04" y2="27.94" width="0.1524" layer="91"/>
<wire x1="66.04" y1="27.94" x2="63.5" y2="30.48" width="0.1524" layer="91"/>
<wire x1="63.5" y1="30.48" x2="63.5" y2="35.56" width="0.1524" layer="91"/>
<wire x1="63.5" y1="35.56" x2="66.04" y2="38.1" width="0.1524" layer="91"/>
<wire x1="66.04" y1="38.1" x2="83.82" y2="38.1" width="0.1524" layer="91"/>
<wire x1="83.82" y1="38.1" x2="86.36" y2="35.56" width="0.1524" layer="91"/>
<wire x1="86.36" y1="35.56" x2="86.36" y2="30.48" width="0.1524" layer="91"/>
<pinref part="IRIDIUM" gate="A" pin="2"/>
<wire x1="86.36" y1="30.48" x2="83.82" y2="27.94" width="0.1524" layer="91"/>
<wire x1="83.82" y1="27.94" x2="78.74" y2="27.94" width="0.1524" layer="91"/>
<label x="71.12" y="38.1" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="P1" gate="G$1" pin="5"/>
<wire x1="60.96" y1="-53.34" x2="73.66" y2="-53.34" width="0.1524" layer="91"/>
<label x="63.5" y="-53.34" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="UCC"/>
<wire x1="-76.2" y1="71.12" x2="-60.96" y2="71.12" width="0.1524" layer="91"/>
<label x="-66.04" y="71.12" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$2" gate="G$1" pin="VDD"/>
<wire x1="2.54" y1="50.8" x2="2.54" y2="63.5" width="0.1524" layer="91"/>
<label x="2.54" y="55.88" size="1.778" layer="95" rot="R90"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="IRIDIUM" gate="A" pin="3"/>
<wire x1="71.12" y1="25.4" x2="63.5" y2="25.4" width="0.1524" layer="91"/>
<wire x1="63.5" y1="25.4" x2="60.96" y2="27.94" width="0.1524" layer="91"/>
<wire x1="60.96" y1="27.94" x2="60.96" y2="38.1" width="0.1524" layer="91"/>
<wire x1="60.96" y1="38.1" x2="71.12" y2="48.26" width="0.1524" layer="91"/>
<wire x1="71.12" y1="48.26" x2="76.2" y2="48.26" width="0.1524" layer="91"/>
<wire x1="76.2" y1="48.26" x2="78.74" y2="48.26" width="0.1524" layer="91"/>
<wire x1="78.74" y1="48.26" x2="88.9" y2="38.1" width="0.1524" layer="91"/>
<wire x1="88.9" y1="38.1" x2="88.9" y2="27.94" width="0.1524" layer="91"/>
<pinref part="IRIDIUM" gate="A" pin="4"/>
<wire x1="88.9" y1="27.94" x2="86.36" y2="25.4" width="0.1524" layer="91"/>
<wire x1="86.36" y1="25.4" x2="78.74" y2="25.4" width="0.1524" layer="91"/>
<pinref part="GND1" gate="1" pin="GND"/>
<junction x="76.2" y="48.26"/>
</segment>
<segment>
<pinref part="IRIDIUM" gate="A" pin="8"/>
<wire x1="78.74" y1="20.32" x2="88.9" y2="20.32" width="0.1524" layer="91"/>
<pinref part="GND2" gate="1" pin="GND"/>
<pinref part="IRIDIUM" gate="A" pin="18"/>
<wire x1="88.9" y1="20.32" x2="96.52" y2="20.32" width="0.1524" layer="91"/>
<wire x1="78.74" y1="7.62" x2="86.36" y2="7.62" width="0.1524" layer="91"/>
<wire x1="86.36" y1="7.62" x2="88.9" y2="10.16" width="0.1524" layer="91"/>
<wire x1="88.9" y1="10.16" x2="88.9" y2="20.32" width="0.1524" layer="91"/>
<junction x="88.9" y="20.32"/>
</segment>
<segment>
<pinref part="GND3" gate="1" pin="GND"/>
<pinref part="IRIDIUM" gate="A" pin="15"/>
<wire x1="50.8" y1="10.16" x2="71.12" y2="10.16" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="R1" gate="G$1" pin="2"/>
<pinref part="GND6" gate="1" pin="GND"/>
<wire x1="7.62" y1="0" x2="7.62" y2="-2.54" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="P1" gate="G$1" pin="1"/>
<wire x1="60.96" y1="-63.5" x2="63.5" y2="-63.5" width="0.1524" layer="91"/>
<pinref part="GND7" gate="1" pin="GND"/>
<wire x1="63.5" y1="-63.5" x2="66.04" y2="-66.04" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="GND"/>
<wire x1="-76.2" y1="55.88" x2="-66.04" y2="55.88" width="0.1524" layer="91"/>
<pinref part="GND4" gate="1" pin="GND"/>
<wire x1="-66.04" y1="55.88" x2="-66.04" y2="53.34" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="U$3" gate="G$1" pin="GND"/>
<pinref part="GND9" gate="1" pin="GND"/>
<wire x1="-93.98" y1="106.68" x2="-93.98" y2="99.06" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="IRIDIUM" gate="A" pin="11"/>
<wire x1="66.04" y1="15.24" x2="71.12" y2="15.24" width="0.1524" layer="91"/>
<wire x1="20.32" y1="22.86" x2="35.56" y2="22.86" width="0.1524" layer="91"/>
<wire x1="35.56" y1="22.86" x2="40.64" y2="27.94" width="0.1524" layer="91"/>
<wire x1="40.64" y1="27.94" x2="53.34" y2="27.94" width="0.1524" layer="91"/>
<wire x1="66.04" y1="15.24" x2="53.34" y2="27.94" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="IRIDIUM" gate="A" pin="13"/>
<wire x1="66.04" y1="12.7" x2="71.12" y2="12.7" width="0.1524" layer="91"/>
<wire x1="20.32" y1="27.94" x2="35.56" y2="27.94" width="0.1524" layer="91"/>
<wire x1="35.56" y1="27.94" x2="40.64" y2="22.86" width="0.1524" layer="91"/>
<wire x1="40.64" y1="22.86" x2="55.88" y2="22.86" width="0.1524" layer="91"/>
<wire x1="55.88" y1="22.86" x2="66.04" y2="12.7" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<wire x1="20.32" y1="17.78" x2="66.04" y2="17.78" width="0.1524" layer="91"/>
<wire x1="66.04" y1="17.78" x2="68.58" y2="20.32" width="0.1524" layer="91"/>
<pinref part="IRIDIUM" gate="A" pin="7"/>
<wire x1="68.58" y1="20.32" x2="71.12" y2="20.32" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<wire x1="20.32" y1="12.7" x2="38.1" y2="12.7" width="0.1524" layer="91"/>
<wire x1="38.1" y1="12.7" x2="50.8" y2="0" width="0.1524" layer="91"/>
<wire x1="50.8" y1="0" x2="88.9" y2="0" width="0.1524" layer="91"/>
<wire x1="88.9" y1="0" x2="104.14" y2="17.78" width="0.1524" layer="91"/>
<wire x1="104.14" y1="17.78" x2="104.14" y2="20.32" width="0.1524" layer="91"/>
<pinref part="IRIDIUM" gate="A" pin="6"/>
<wire x1="104.14" y1="20.32" x2="101.6" y2="22.86" width="0.1524" layer="91"/>
<wire x1="101.6" y1="22.86" x2="78.74" y2="22.86" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$1" class="0">
<segment>
<wire x1="20.32" y1="7.62" x2="40.64" y2="7.62" width="0.1524" layer="91"/>
<wire x1="40.64" y1="7.62" x2="48.26" y2="15.24" width="0.1524" layer="91"/>
<wire x1="48.26" y1="15.24" x2="53.34" y2="15.24" width="0.1524" layer="91"/>
<wire x1="53.34" y1="15.24" x2="60.96" y2="22.86" width="0.1524" layer="91"/>
<pinref part="IRIDIUM" gate="A" pin="5"/>
<wire x1="60.96" y1="22.86" x2="71.12" y2="22.86" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<wire x1="20.32" y1="2.54" x2="60.96" y2="2.54" width="0.1524" layer="91"/>
<wire x1="60.96" y1="2.54" x2="63.5" y2="5.08" width="0.1524" layer="91"/>
<pinref part="IRIDIUM" gate="A" pin="19"/>
<wire x1="63.5" y1="5.08" x2="71.12" y2="5.08" width="0.1524" layer="91"/>
</segment>
</net>
<net name="7.4V" class="0">
<segment>
<pinref part="P1" gate="G$1" pin="4"/>
<wire x1="60.96" y1="-55.88" x2="73.66" y2="-55.88" width="0.1524" layer="91"/>
<label x="68.58" y="-55.88" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$12" class="0">
<segment>
<pinref part="P1" gate="G$1" pin="3"/>
<wire x1="60.96" y1="-58.42" x2="81.28" y2="-58.42" width="0.1524" layer="91"/>
<wire x1="81.28" y1="-58.42" x2="83.82" y2="-55.88" width="0.1524" layer="91"/>
<wire x1="83.82" y1="-55.88" x2="83.82" y2="-50.8" width="0.1524" layer="91"/>
<wire x1="83.82" y1="-50.8" x2="86.36" y2="-48.26" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$13" class="0">
<segment>
<wire x1="83.82" y1="-48.26" x2="86.36" y2="-50.8" width="0.1524" layer="91"/>
<wire x1="86.36" y1="-50.8" x2="86.36" y2="-55.88" width="0.1524" layer="91"/>
<pinref part="P1" gate="G$1" pin="2"/>
<wire x1="86.36" y1="-55.88" x2="81.28" y2="-60.96" width="0.1524" layer="91"/>
<wire x1="81.28" y1="-60.96" x2="60.96" y2="-60.96" width="0.1524" layer="91"/>
</segment>
</net>
<net name="3.3V" class="0">
<segment>
<wire x1="20.32" y1="38.1" x2="35.56" y2="38.1" width="0.1524" layer="91"/>
<label x="30.48" y="38.1" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$3" gate="G$1" pin="VCC"/>
<wire x1="-99.06" y1="106.68" x2="-99.06" y2="101.6" width="0.1524" layer="91"/>
<wire x1="-99.06" y1="101.6" x2="-114.3" y2="101.6" width="0.1524" layer="91"/>
<pinref part="R2" gate="G$1" pin="2"/>
<wire x1="-114.3" y1="101.6" x2="-124.46" y2="101.6" width="0.1524" layer="91"/>
<wire x1="-124.46" y1="101.6" x2="-124.46" y2="104.14" width="0.1524" layer="91"/>
<wire x1="-114.3" y1="101.6" x2="-114.3" y2="91.44" width="0.1524" layer="91"/>
<junction x="-114.3" y="101.6"/>
<label x="-111.76" y="91.44" size="1.778" layer="95"/>
</segment>
</net>
<net name="PD8=TX" class="0">
<segment>
<pinref part="U$4" gate="G$1" pin="PD8"/>
<wire x1="-20.32" y1="106.68" x2="-22.86" y2="104.14" width="0.1524" layer="91"/>
<wire x1="-22.86" y1="104.14" x2="-22.86" y2="66.04" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="RX"/>
<wire x1="-22.86" y1="66.04" x2="-76.2" y2="66.04" width="0.1524" layer="91"/>
<label x="-66.04" y="66.04" size="1.778" layer="95"/>
</segment>
</net>
<net name="PD9=RX" class="0">
<segment>
<pinref part="U$4" gate="G$1" pin="PD9"/>
<wire x1="-20.32" y1="71.12" x2="-20.32" y2="63.5" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="TX"/>
<wire x1="-20.32" y1="63.5" x2="-22.86" y2="60.96" width="0.1524" layer="91"/>
<wire x1="-22.86" y1="60.96" x2="-76.2" y2="60.96" width="0.1524" layer="91"/>
<label x="-66.04" y="60.96" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="U$4" gate="G$1" pin="PB12"/>
<wire x1="-30.48" y1="106.68" x2="-30.48" y2="132.08" width="0.1524" layer="91"/>
<wire x1="-30.48" y1="132.08" x2="-33.02" y2="134.62" width="0.1524" layer="91"/>
<wire x1="-33.02" y1="134.62" x2="-60.96" y2="134.62" width="0.1524" layer="91"/>
<wire x1="-60.96" y1="134.62" x2="-73.66" y2="147.32" width="0.1524" layer="91"/>
<pinref part="U$3" gate="G$1" pin="NSS"/>
<wire x1="-73.66" y1="147.32" x2="-78.74" y2="147.32" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<wire x1="-33.02" y1="73.66" x2="-33.02" y2="129.54" width="0.1524" layer="91"/>
<wire x1="-33.02" y1="129.54" x2="-35.56" y2="132.08" width="0.1524" layer="91"/>
<wire x1="-35.56" y1="132.08" x2="-63.5" y2="132.08" width="0.1524" layer="91"/>
<wire x1="-63.5" y1="132.08" x2="-73.66" y2="142.24" width="0.1524" layer="91"/>
<pinref part="U$3" gate="G$1" pin="SCK"/>
<wire x1="-73.66" y1="142.24" x2="-78.74" y2="142.24" width="0.1524" layer="91"/>
<pinref part="U$4" gate="G$1" pin="PB13"/>
<wire x1="-30.48" y1="71.12" x2="-33.02" y2="73.66" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$15" class="0">
<segment>
<pinref part="U$4" gate="G$1" pin="PB15"/>
<wire x1="-35.56" y1="71.12" x2="-38.1" y2="73.66" width="0.1524" layer="91"/>
<wire x1="-38.1" y1="73.66" x2="-38.1" y2="121.92" width="0.1524" layer="91"/>
<wire x1="-38.1" y1="121.92" x2="-43.18" y2="127" width="0.1524" layer="91"/>
<wire x1="-43.18" y1="127" x2="-63.5" y2="127" width="0.1524" layer="91"/>
<wire x1="-63.5" y1="127" x2="-73.66" y2="137.16" width="0.1524" layer="91"/>
<pinref part="U$3" gate="G$1" pin="MOSI"/>
<wire x1="-73.66" y1="137.16" x2="-78.74" y2="137.16" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$16" class="0">
<segment>
<pinref part="U$4" gate="G$1" pin="PB14"/>
<wire x1="-35.56" y1="106.68" x2="-35.56" y2="116.84" width="0.1524" layer="91"/>
<wire x1="-35.56" y1="116.84" x2="-60.96" y2="116.84" width="0.1524" layer="91"/>
<wire x1="-60.96" y1="116.84" x2="-76.2" y2="132.08" width="0.1524" layer="91"/>
<pinref part="U$3" gate="G$1" pin="MISO"/>
<wire x1="-76.2" y1="132.08" x2="-78.74" y2="132.08" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$17" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="BUSY"/>
<wire x1="-114.3" y1="147.32" x2="-116.84" y2="149.86" width="0.1524" layer="91"/>
<wire x1="-116.84" y1="149.86" x2="-116.84" y2="160.02" width="0.1524" layer="91"/>
<pinref part="U$4" gate="G$1" pin="PA6"/>
<wire x1="-116.84" y1="160.02" x2="-71.12" y2="160.02" width="0.1524" layer="91"/>
<wire x1="-71.12" y1="160.02" x2="-53.34" y2="142.24" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$18" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="NRST"/>
<wire x1="-114.3" y1="127" x2="-121.92" y2="134.62" width="0.1524" layer="91"/>
<wire x1="-121.92" y1="134.62" x2="-121.92" y2="162.56" width="0.1524" layer="91"/>
<wire x1="-121.92" y1="162.56" x2="-71.12" y2="162.56" width="0.1524" layer="91"/>
<pinref part="U$4" gate="G$1" pin="PA5"/>
<wire x1="-71.12" y1="162.56" x2="-55.88" y2="147.32" width="0.1524" layer="91"/>
<wire x1="-55.88" y1="147.32" x2="-53.34" y2="147.32" width="0.1524" layer="91"/>
<pinref part="R2" gate="G$1" pin="1"/>
<wire x1="-124.46" y1="114.3" x2="-121.92" y2="116.84" width="0.1524" layer="91"/>
<wire x1="-121.92" y1="116.84" x2="-121.92" y2="134.62" width="0.1524" layer="91"/>
<junction x="-121.92" y="134.62"/>
</segment>
</net>
<net name="N$10" class="0">
<segment>
<wire x1="-2.54" y1="53.34" x2="-2.54" y2="88.9" width="0.1524" layer="91"/>
<wire x1="-2.54" y1="88.9" x2="2.54" y2="93.98" width="0.1524" layer="91"/>
<wire x1="2.54" y1="93.98" x2="2.54" y2="104.14" width="0.1524" layer="91"/>
<pinref part="U$4" gate="G$1" pin="PD1"/>
<wire x1="2.54" y1="104.14" x2="5.08" y2="106.68" width="0.1524" layer="91"/>
<pinref part="U$2" gate="G$1" pin="RXD"/>
<wire x1="0" y1="50.8" x2="-2.54" y2="53.34" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$14" class="0">
<segment>
<pinref part="U$2" gate="G$1" pin="VSS"/>
<wire x1="5.08" y1="50.8" x2="5.08" y2="58.42" width="0.1524" layer="91"/>
<pinref part="GND5" gate="1" pin="GND"/>
</segment>
</net>
<net name="N$9" class="0">
<segment>
<pinref part="U$2" gate="G$1" pin="TXD"/>
<wire x1="7.62" y1="50.8" x2="10.16" y2="50.8" width="0.1524" layer="91"/>
<wire x1="10.16" y1="50.8" x2="12.7" y2="53.34" width="0.1524" layer="91"/>
<wire x1="12.7" y1="53.34" x2="12.7" y2="63.5" width="0.1524" layer="91"/>
<wire x1="12.7" y1="63.5" x2="10.16" y2="66.04" width="0.1524" layer="91"/>
<pinref part="U$4" gate="G$1" pin="PD0"/>
<wire x1="10.16" y1="66.04" x2="10.16" y2="71.12" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$11" class="0">
<segment>
<pinref part="U$2" gate="G$1" pin="RS"/>
<wire x1="7.62" y1="17.78" x2="7.62" y2="10.16" width="0.1524" layer="91"/>
<pinref part="R1" gate="G$1" pin="1"/>
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
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
<note version="8.4" severity="warning">
Since Version 8.4, EAGLE supports properties for SPICE simulation. 
Probes in schematics and SPICE mapping objects found in parts and library devices
will not be understood with this version. Update EAGLE to the latest version
for full support of SPICE simulation. 
</note>
</compatibility>
</eagle>
