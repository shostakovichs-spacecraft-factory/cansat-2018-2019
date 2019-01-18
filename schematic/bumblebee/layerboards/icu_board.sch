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
<library name="bluepill">
<packages>
<package name="BLUEPIL">
<description>Microcontroller from st micro on board</description>
<pad name="GND0" x="-24.13" y="7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="GND1" x="-21.59" y="7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="3V3_0" x="-19.05" y="7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="RESET" x="-16.51" y="7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="B11" x="-13.97" y="7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="B10" x="-11.43" y="7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="B1" x="-8.89" y="7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="B0" x="-6.35" y="7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="A7" x="-3.81" y="7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="A6" x="-1.27" y="7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="A5" x="1.27" y="7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="A4" x="3.81" y="7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="A3" x="6.35" y="7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="A2" x="8.89" y="7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="A1" x="11.43" y="7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="A0" x="13.97" y="7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="C15" x="16.51" y="7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="C14" x="19.05" y="7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="C13" x="21.59" y="7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="VB" x="24.13" y="7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="B12" x="-24.13" y="-7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="B13" x="-21.59" y="-7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="B14" x="-19.05" y="-7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="B15" x="-16.51" y="-7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="A8" x="-13.97" y="-7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="A9" x="-11.43" y="-7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="A10" x="-8.89" y="-7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="A11" x="-6.35" y="-7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="A12" x="-3.81" y="-7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="A15" x="-1.27" y="-7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="B3" x="1.27" y="-7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="B4" x="3.81" y="-7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="B5" x="6.35" y="-7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="B6" x="8.89" y="-7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="B7" x="11.43" y="-7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="B8" x="13.97" y="-7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="B9" x="16.51" y="-7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="5V" x="19.05" y="-7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="GND2" x="21.59" y="-7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="3V3_1" x="24.13" y="-7.62" drill="0.8" shape="long" rot="R90"/>
<polygon width="0.127" layer="21">
<vertex x="26.5" y="-11.5"/>
<vertex x="26.5" y="-11"/>
<vertex x="26.5" y="11.5"/>
</polygon>
<wire x1="26.5" y1="11.5" x2="-26.5" y2="11.5" width="0.127" layer="21"/>
<wire x1="-26.5" y1="11.5" x2="-26.5" y2="-11.5" width="0.127" layer="21"/>
<wire x1="26.5" y1="11.5" x2="26.5" y2="-11.5" width="0.127" layer="21"/>
<wire x1="-26.5" y1="-11.5" x2="26.5" y2="-11.5" width="0.127" layer="21"/>
<text x="-26.67" y="12.7" size="1.27" layer="25">&gt;NAME</text>
<text x="-26.67" y="-13.97" size="1.27" layer="27">&gt;VALUE</text>
<pad name="GND3" x="21.59" y="3.81" drill="0.8" shape="long" rot="R180"/>
<pad name="SWCLK" x="21.59" y="1.27" drill="0.8" shape="long" rot="R180"/>
<pad name="SWDIO" x="21.59" y="-1.27" drill="0.8" shape="long" rot="R180"/>
<pad name="3V3_2" x="21.59" y="-3.81" drill="0.8" shape="long" rot="R180"/>
</package>
</packages>
<symbols>
<symbol name="BLUEPILL">
<description>bluepill board</description>
<pin name="GND" x="20.32" y="43.18" length="middle" rot="R180"/>
<pin name="PB0" x="-20.32" y="33.02" length="middle"/>
<pin name="PB1" x="-20.32" y="27.94" length="middle"/>
<pin name="PB3" x="-20.32" y="22.86" length="middle"/>
<pin name="PB4" x="-20.32" y="17.78" length="middle"/>
<pin name="PB5" x="-20.32" y="12.7" length="middle"/>
<pin name="PB6" x="-20.32" y="7.62" length="middle"/>
<pin name="PB7" x="-20.32" y="2.54" length="middle"/>
<pin name="PB8" x="-20.32" y="-2.54" length="middle"/>
<pin name="PB9" x="-20.32" y="-7.62" length="middle"/>
<pin name="PB10" x="-20.32" y="-12.7" length="middle"/>
<pin name="PB11" x="-20.32" y="-17.78" length="middle"/>
<pin name="PB12" x="-20.32" y="-22.86" length="middle"/>
<pin name="PB13" x="-20.32" y="-27.94" length="middle"/>
<pin name="PB14" x="-20.32" y="-33.02" length="middle"/>
<pin name="PB15" x="-20.32" y="-38.1" length="middle"/>
<pin name="RESET" x="-20.32" y="43.18" length="middle"/>
<pin name="5V" x="20.32" y="33.02" length="middle" rot="R180"/>
<pin name="3V3" x="20.32" y="38.1" length="middle" rot="R180"/>
<pin name="VBAT" x="-20.32" y="38.1" length="middle"/>
<pin name="PA0" x="20.32" y="27.94" length="middle" rot="R180"/>
<pin name="PA1" x="20.32" y="22.86" length="middle" rot="R180"/>
<pin name="PA2" x="20.32" y="17.78" length="middle" rot="R180"/>
<pin name="PA3" x="20.32" y="12.7" length="middle" rot="R180"/>
<pin name="PA4" x="20.32" y="7.62" length="middle" rot="R180"/>
<pin name="PA5" x="20.32" y="2.54" length="middle" rot="R180"/>
<pin name="PA6" x="20.32" y="-2.54" length="middle" rot="R180"/>
<pin name="PA7" x="20.32" y="-7.62" length="middle" rot="R180"/>
<pin name="PA8" x="20.32" y="-12.7" length="middle" rot="R180"/>
<pin name="PA9" x="20.32" y="-17.78" length="middle" rot="R180"/>
<pin name="PA10" x="20.32" y="-22.86" length="middle" rot="R180"/>
<pin name="PA11" x="20.32" y="-27.94" length="middle" rot="R180"/>
<pin name="PA12" x="20.32" y="-33.02" length="middle" rot="R180"/>
<pin name="PA15" x="20.32" y="-38.1" length="middle" rot="R180"/>
<pin name="PC13" x="-20.32" y="-43.18" length="middle"/>
<pin name="PC14" x="-20.32" y="-48.26" length="middle"/>
<pin name="PC15" x="-20.32" y="-53.34" length="middle"/>
<wire x1="-15.24" y1="45.72" x2="-15.24" y2="-55.88" width="0.254" layer="94"/>
<wire x1="-15.24" y1="-55.88" x2="15.24" y2="-55.88" width="0.254" layer="94"/>
<wire x1="15.24" y1="-55.88" x2="15.24" y2="45.72" width="0.254" layer="94"/>
<wire x1="15.24" y1="45.72" x2="-15.24" y2="45.72" width="0.254" layer="94"/>
<text x="10.16" y="50.8" size="1.27" layer="95">&gt;NAME</text>
<text x="10.16" y="48.26" size="1.27" layer="96">&gt;VALUE</text>
<pin name="SWDIO" x="-2.54" y="50.8" length="middle" rot="R270"/>
<pin name="SWCLK" x="2.54" y="50.8" length="middle" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="BLUEPILL">
<description>BLUEPILL</description>
<gates>
<gate name="G$1" symbol="BLUEPILL" x="0" y="0"/>
</gates>
<devices>
<device name="THEONLYONE" package="BLUEPIL">
<connects>
<connect gate="G$1" pin="3V3" pad="3V3_0 3V3_1 3V3_2"/>
<connect gate="G$1" pin="5V" pad="5V"/>
<connect gate="G$1" pin="GND" pad="GND0 GND1 GND2 GND3"/>
<connect gate="G$1" pin="PA0" pad="A0"/>
<connect gate="G$1" pin="PA1" pad="A1"/>
<connect gate="G$1" pin="PA10" pad="A10"/>
<connect gate="G$1" pin="PA11" pad="A11"/>
<connect gate="G$1" pin="PA12" pad="A12"/>
<connect gate="G$1" pin="PA15" pad="A15"/>
<connect gate="G$1" pin="PA2" pad="A2"/>
<connect gate="G$1" pin="PA3" pad="A3"/>
<connect gate="G$1" pin="PA4" pad="A4"/>
<connect gate="G$1" pin="PA5" pad="A5"/>
<connect gate="G$1" pin="PA6" pad="A6"/>
<connect gate="G$1" pin="PA7" pad="A7"/>
<connect gate="G$1" pin="PA8" pad="A8"/>
<connect gate="G$1" pin="PA9" pad="A9"/>
<connect gate="G$1" pin="PB0" pad="B0"/>
<connect gate="G$1" pin="PB1" pad="B1"/>
<connect gate="G$1" pin="PB10" pad="B10"/>
<connect gate="G$1" pin="PB11" pad="B11"/>
<connect gate="G$1" pin="PB12" pad="B12"/>
<connect gate="G$1" pin="PB13" pad="B13"/>
<connect gate="G$1" pin="PB14" pad="B14"/>
<connect gate="G$1" pin="PB15" pad="B15"/>
<connect gate="G$1" pin="PB3" pad="B3"/>
<connect gate="G$1" pin="PB4" pad="B4"/>
<connect gate="G$1" pin="PB5" pad="B5"/>
<connect gate="G$1" pin="PB6" pad="B6"/>
<connect gate="G$1" pin="PB7" pad="B7"/>
<connect gate="G$1" pin="PB8" pad="B8"/>
<connect gate="G$1" pin="PB9" pad="B9"/>
<connect gate="G$1" pin="PC13" pad="C13"/>
<connect gate="G$1" pin="PC14" pad="C14"/>
<connect gate="G$1" pin="PC15" pad="C15"/>
<connect gate="G$1" pin="RESET" pad="RESET"/>
<connect gate="G$1" pin="SWCLK" pad="SWCLK"/>
<connect gate="G$1" pin="SWDIO" pad="SWDIO"/>
<connect gate="G$1" pin="VBAT" pad="VB"/>
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
<part name="U$1" library="bluepill" deviceset="BLUEPILL" device="THEONLYONE"/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="0" y="0" smashed="yes">
<attribute name="NAME" x="10.16" y="50.8" size="1.27" layer="95"/>
<attribute name="VALUE" x="10.16" y="48.26" size="1.27" layer="96"/>
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
</eagle>
