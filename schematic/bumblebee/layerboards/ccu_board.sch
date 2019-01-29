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
<package name="PX4FLOW_TMP">
<pad name="P$1" x="-1.27" y="5.08" drill="0.6" shape="square"/>
<pad name="P$2" x="1.27" y="5.08" drill="0.6" shape="square"/>
<pad name="P$3" x="-3.81" y="3.81" drill="0.6" shape="square"/>
<pad name="P$4" x="-3.81" y="2.54" drill="0.6" shape="square"/>
<pad name="P$5" x="-3.81" y="0" drill="0.6" shape="square"/>
<pad name="P$6" x="-3.81" y="-1.27" drill="0.6" shape="square"/>
<pad name="P$7" x="-3.81" y="-2.54" drill="0.6" shape="square"/>
<pad name="P$8" x="-3.81" y="-3.81" drill="0.6" shape="square"/>
<pad name="P$9" x="3.81" y="-3.81" drill="0.6" shape="square"/>
<pad name="P$10" x="3.81" y="-2.54" drill="0.6" shape="square"/>
<pad name="P$11" x="3.81" y="0" drill="0.6" shape="square"/>
<pad name="P$12" x="3.81" y="1.27" drill="0.6" shape="square"/>
<pad name="P$13" x="3.81" y="2.54" drill="0.6" shape="square"/>
<pad name="P$14" x="3.81" y="3.81" drill="0.6" shape="square"/>
<pad name="P$15" x="0" y="-5.08" drill="0.6" shape="square"/>
<pad name="P$16" x="1.27" y="-5.08" drill="0.6" shape="square"/>
<pad name="P$17" x="2.54" y="-5.08" drill="0.6" shape="square"/>
<pad name="P$18" x="-1.27" y="-5.08" drill="0.6" shape="square"/>
<pad name="P$19" x="-2.54" y="-5.08" drill="0.6" shape="square"/>
<text x="0" y="-3.81" size="1.27" layer="21" rot="R90">REDRAW</text>
<pad name="P$20" x="-2.54" y="5.08" drill="0.6" shape="square"/>
<pad name="P$21" x="2.54" y="5.08" drill="0.6" shape="square"/>
</package>
<package name="CAM_BIG">
<rectangle x1="-19.2" y1="-19.2" x2="19.2" y2="19.2" layer="21"/>
<pad name="TX" x="-13" y="1.27" drill="0.8" shape="square"/>
<pad name="GND" x="-13" y="3.81" drill="0.8" shape="square"/>
<pad name="RX" x="-13" y="-1.27" drill="0.8" shape="square"/>
<pad name="5V" x="-13" y="-3.81" drill="0.8" shape="square"/>
<text x="-17.1" y="22.3" size="1.27" layer="25">&gt;NAME</text>
<text x="-16.6" y="-22.6" size="1.27" layer="27">&gt;VALUE</text>
</package>
<package name="CAM">
<rectangle x1="-14" y1="-10" x2="14" y2="10" layer="21"/>
<dimension x1="-14" y1="10" x2="14" y2="10" x3="0" y3="15.5" textsize="1.27" layer="21"/>
<dimension x1="-14" y1="-10" x2="-14" y2="10" x3="27.7" y3="0" textsize="1.27" layer="21"/>
<pad name="RX" x="-13" y="1.27" drill="0.8" shape="square"/>
<pad name="TX" x="-13" y="-1.27" drill="0.8" shape="square"/>
<pad name="5V" x="-13" y="-3.81" drill="0.8" shape="square"/>
<pad name="GND" x="-13" y="3.81" drill="0.8" shape="square"/>
<pad name="CV85" x="-13" y="-6.35" drill="0.8" shape="square"/>
<text x="-12.7" y="11.43" size="1.27" layer="25">&gt;NAME</text>
<text x="-12.7" y="-12.7" size="1.27" layer="27">&gt;VALUE</text>
<hole x="-12.5" y="8.5" drill="2.5"/>
<hole x="12.5" y="8.5" drill="2.5"/>
<hole x="12.5" y="-8.5" drill="2.5"/>
<hole x="-12.5" y="-8.5" drill="2.5"/>
</package>
</packages>
<symbols>
<symbol name="PX4FLOW">
<wire x1="-12.7" y1="-25.4" x2="-12.7" y2="12.7" width="0.254" layer="94"/>
<wire x1="-12.7" y1="12.7" x2="22.86" y2="12.7" width="0.254" layer="94"/>
<wire x1="22.86" y1="12.7" x2="22.86" y2="-25.4" width="0.254" layer="94"/>
<wire x1="22.86" y1="-25.4" x2="-12.7" y2="-25.4" width="0.254" layer="94"/>
<pin name="5V" x="27.94" y="2.54" length="middle" rot="R180"/>
<pin name="GND" x="27.94" y="0" length="middle" rot="R180"/>
<pin name="USB_D+" x="27.94" y="-5.08" length="middle" rot="R180"/>
<pin name="USB_D-" x="27.94" y="-7.62" length="middle" rot="R180"/>
<pin name="USART2_RTS" x="27.94" y="-12.7" length="middle" rot="R180"/>
<pin name="USART2_CTS" x="27.94" y="-15.24" length="middle" rot="R180"/>
<pin name="USART2_RX" x="27.94" y="-17.78" length="middle" rot="R180"/>
<pin name="USART2_TX" x="27.94" y="-20.32" length="middle" rot="R180"/>
<pin name="USART3_CTS" x="-17.78" y="-12.7" length="middle"/>
<pin name="USART3_RTS" x="-17.78" y="-10.16" length="middle"/>
<pin name="USART3_TX" x="-17.78" y="-7.62" length="middle"/>
<pin name="USART3_RX" x="-17.78" y="-5.08" length="middle"/>
<pin name="SDA" x="-17.78" y="-20.32" length="middle"/>
<pin name="SCL" x="-17.78" y="-17.78" length="middle"/>
<pin name="SONAR_PW" x="7.62" y="17.78" length="middle" rot="R270"/>
<pin name="SONAR_AN" x="5.08" y="17.78" length="middle" rot="R270"/>
<pin name="SONAR_BW" x="10.16" y="17.78" length="middle" rot="R270"/>
<pin name="SONAR_RX" x="2.54" y="17.78" length="middle" rot="R270"/>
<pin name="SONAR_TX" x="0" y="17.78" length="middle" rot="R270"/>
<pin name="SWDIO" x="-17.78" y="2.54" length="middle"/>
<pin name="SWCLK" x="-17.78" y="0" length="middle"/>
</symbol>
<symbol name="CAM_BIG">
<pin name="TX" x="-10.16" y="2.54" length="middle"/>
<pin name="RX" x="-10.16" y="-2.54" length="middle"/>
<pin name="GND" x="-10.16" y="7.62" length="middle"/>
<pin name="5V" x="-10.16" y="-7.62" length="middle"/>
<wire x1="-5.08" y1="10.16" x2="5.08" y2="10.16" width="0.254" layer="94"/>
<wire x1="5.08" y1="10.16" x2="5.08" y2="-10.16" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-10.16" x2="-5.08" y2="10.16" width="0.254" layer="94"/>
<text x="-5.08" y="15.24" size="1.27" layer="95">&gt;NAME</text>
<text x="-5.08" y="-15.24" size="1.27" layer="96">&gt;VALUE</text>
<wire x1="-5.08" y1="-10.16" x2="5.08" y2="-10.16" width="0.254" layer="94"/>
</symbol>
<symbol name="CAM">
<pin name="RX" x="-10.16" y="2.54" length="middle"/>
<pin name="TX" x="-10.16" y="-2.54" length="middle"/>
<pin name="5V" x="-10.16" y="-7.62" length="middle"/>
<pin name="GND" x="-10.16" y="7.62" length="middle"/>
<pin name="CV85" x="-10.16" y="-12.7" length="middle"/>
<wire x1="-5.08" y1="10.16" x2="5.08" y2="10.16" width="0.254" layer="94"/>
<wire x1="5.08" y1="10.16" x2="5.08" y2="-15.24" width="0.254" layer="94"/>
<wire x1="5.08" y1="-15.24" x2="-5.08" y2="-15.24" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-15.24" x2="-5.08" y2="10.16" width="0.254" layer="94"/>
<text x="-5.08" y="12.7" size="1.27" layer="95">&gt;NAME</text>
<text x="-5.08" y="-20.32" size="1.27" layer="96">&gt;VALUE</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="PX4FLOW">
<gates>
<gate name="G$1" symbol="PX4FLOW" x="0" y="0"/>
</gates>
<devices>
<device name="" package="PX4FLOW_TMP">
<connects>
<connect gate="G$1" pin="5V" pad="P$1"/>
<connect gate="G$1" pin="GND" pad="P$2"/>
<connect gate="G$1" pin="SCL" pad="P$3"/>
<connect gate="G$1" pin="SDA" pad="P$4"/>
<connect gate="G$1" pin="SONAR_AN" pad="P$5"/>
<connect gate="G$1" pin="SONAR_BW" pad="P$6"/>
<connect gate="G$1" pin="SONAR_PW" pad="P$7"/>
<connect gate="G$1" pin="SONAR_RX" pad="P$8"/>
<connect gate="G$1" pin="SONAR_TX" pad="P$9"/>
<connect gate="G$1" pin="SWCLK" pad="P$20"/>
<connect gate="G$1" pin="SWDIO" pad="P$21"/>
<connect gate="G$1" pin="USART2_CTS" pad="P$10"/>
<connect gate="G$1" pin="USART2_RTS" pad="P$11"/>
<connect gate="G$1" pin="USART2_RX" pad="P$12"/>
<connect gate="G$1" pin="USART2_TX" pad="P$13"/>
<connect gate="G$1" pin="USART3_CTS" pad="P$14"/>
<connect gate="G$1" pin="USART3_RTS" pad="P$15"/>
<connect gate="G$1" pin="USART3_RX" pad="P$16"/>
<connect gate="G$1" pin="USART3_TX" pad="P$17"/>
<connect gate="G$1" pin="USB_D+" pad="P$18"/>
<connect gate="G$1" pin="USB_D-" pad="P$19"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="CAM_BIG">
<gates>
<gate name="G$1" symbol="CAM_BIG" x="0" y="0"/>
</gates>
<devices>
<device name="" package="CAM_BIG">
<connects>
<connect gate="G$1" pin="5V" pad="5V"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="RX" pad="RX"/>
<connect gate="G$1" pin="TX" pad="TX"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="CAM">
<gates>
<gate name="G$1" symbol="CAM" x="0" y="0"/>
</gates>
<devices>
<device name="" package="CAM">
<connects>
<connect gate="G$1" pin="5V" pad="5V"/>
<connect gate="G$1" pin="CV85" pad="CV85"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="RX" pad="RX"/>
<connect gate="G$1" pin="TX" pad="TX"/>
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
</packages>
<symbols>
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
</symbols>
<devicesets>
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
<part name="U$1" library="bluepill" deviceset="PX4FLOW" device=""/>
<part name="U$2" library="bluepill" deviceset="CAM_BIG" device=""/>
<part name="GND1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="U$3" library="bluepill" deviceset="CAM" device=""/>
<part name="GND2" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="P1" library="con-jst-eh" deviceset="B4B-EH-A" device=""/>
<part name="GND3" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="U$4" library="MCP2551" deviceset="MCP2551" device=""/>
<part name="GND4" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND5" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="R1" library="ngspice-simulation" library_urn="urn:adsk.eagle:library:527439" deviceset="R" device=""/>
<part name="GND6" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="12.7" y="-12.7" smashed="yes"/>
<instance part="U$2" gate="G$1" x="-30.48" y="-20.32" smashed="yes" rot="R180">
<attribute name="NAME" x="-25.4" y="-35.56" size="1.27" layer="95" rot="R180"/>
<attribute name="VALUE" x="-25.4" y="-5.08" size="1.27" layer="96" rot="R180"/>
</instance>
<instance part="GND1" gate="1" x="-17.78" y="-33.02" smashed="yes">
<attribute name="VALUE" x="-20.32" y="-35.56" size="1.778" layer="96"/>
</instance>
<instance part="U$3" gate="G$1" x="68.58" y="-33.02" smashed="yes">
<attribute name="NAME" x="63.5" y="-20.32" size="1.27" layer="95"/>
<attribute name="VALUE" x="63.5" y="-53.34" size="1.27" layer="96"/>
</instance>
<instance part="GND2" gate="1" x="50.8" y="-25.4" smashed="yes">
<attribute name="VALUE" x="48.26" y="-27.94" size="1.778" layer="96"/>
</instance>
<instance part="P1" gate="G$1" x="139.7" y="-15.24" smashed="yes">
<attribute name="NAME" x="138.43" y="-6.985" size="1.778" layer="95"/>
<attribute name="VALUE" x="138.43" y="-22.86" size="1.778" layer="95"/>
</instance>
<instance part="GND3" gate="1" x="45.72" y="-15.24" smashed="yes">
<attribute name="VALUE" x="43.18" y="-17.78" size="1.778" layer="96"/>
</instance>
<instance part="U$4" gate="G$1" x="93.98" y="-10.16" smashed="yes"/>
<instance part="GND4" gate="1" x="66.04" y="-12.7" smashed="yes">
<attribute name="VALUE" x="63.5" y="-15.24" size="1.778" layer="96"/>
</instance>
<instance part="GND5" gate="1" x="124.46" y="-10.16" smashed="yes">
<attribute name="VALUE" x="121.92" y="-12.7" size="1.778" layer="96"/>
</instance>
<instance part="R1" gate="G$1" x="116.84" y="-7.62" smashed="yes">
<attribute name="NAME" x="114.3" y="-5.08" size="1.778" layer="95"/>
<attribute name="VALUE" x="114.3" y="-11.43" size="1.778" layer="96"/>
</instance>
<instance part="GND6" gate="1" x="132.08" y="-22.86" smashed="yes">
<attribute name="VALUE" x="129.54" y="-25.4" size="1.778" layer="96"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="USART3_RX"/>
<wire x1="-5.08" y1="-17.78" x2="-7.62" y2="-17.78" width="0.1524" layer="91"/>
<wire x1="-7.62" y1="-17.78" x2="-10.16" y2="-20.32" width="0.1524" layer="91"/>
<wire x1="-10.16" y1="-20.32" x2="-15.24" y2="-20.32" width="0.1524" layer="91"/>
<wire x1="-15.24" y1="-20.32" x2="-17.78" y2="-22.86" width="0.1524" layer="91"/>
<pinref part="U$2" gate="G$1" pin="TX"/>
<wire x1="-17.78" y1="-22.86" x2="-20.32" y2="-22.86" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="U$2" gate="G$1" pin="RX"/>
<wire x1="-20.32" y1="-17.78" x2="-10.16" y2="-17.78" width="0.1524" layer="91"/>
<wire x1="-10.16" y1="-17.78" x2="-7.62" y2="-20.32" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="USART3_TX"/>
<wire x1="-7.62" y1="-20.32" x2="-5.08" y2="-20.32" width="0.1524" layer="91"/>
</segment>
</net>
<net name="5V_CCU" class="0">
<segment>
<pinref part="U$2" gate="G$1" pin="5V"/>
<wire x1="-20.32" y1="-12.7" x2="-10.16" y2="-12.7" width="0.1524" layer="91"/>
<label x="-17.78" y="-12.7" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$3" gate="G$1" pin="5V"/>
<wire x1="58.42" y1="-40.64" x2="43.18" y2="-40.64" width="0.1524" layer="91"/>
<label x="43.18" y="-40.64" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="5V"/>
<wire x1="40.64" y1="-10.16" x2="53.34" y2="-10.16" width="0.1524" layer="91"/>
<label x="45.72" y="-10.16" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$4" gate="G$1" pin="VDD"/>
<wire x1="78.74" y1="-12.7" x2="71.12" y2="-12.7" width="0.1524" layer="91"/>
<label x="71.12" y="-12.7" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="P1" gate="G$1" pin="1"/>
<wire x1="134.62" y1="-10.16" x2="129.54" y2="-5.08" width="0.1524" layer="91"/>
<wire x1="129.54" y1="-5.08" x2="121.92" y2="-5.08" width="0.1524" layer="91"/>
<label x="121.92" y="-5.08" size="1.778" layer="95"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="U$2" gate="G$1" pin="GND"/>
<pinref part="GND1" gate="1" pin="GND"/>
<wire x1="-20.32" y1="-27.94" x2="-17.78" y2="-30.48" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="U$3" gate="G$1" pin="GND"/>
<wire x1="58.42" y1="-25.4" x2="55.88" y2="-25.4" width="0.1524" layer="91"/>
<wire x1="55.88" y1="-25.4" x2="53.34" y2="-22.86" width="0.1524" layer="91"/>
<pinref part="GND2" gate="1" pin="GND"/>
<wire x1="53.34" y1="-22.86" x2="50.8" y2="-22.86" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="GND"/>
<pinref part="GND3" gate="1" pin="GND"/>
<wire x1="40.64" y1="-12.7" x2="45.72" y2="-12.7" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND4" gate="1" pin="GND"/>
<pinref part="U$4" gate="G$1" pin="VSS"/>
<wire x1="66.04" y1="-10.16" x2="78.74" y2="-10.16" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="R1" gate="G$1" pin="2"/>
<pinref part="GND5" gate="1" pin="GND"/>
<wire x1="121.92" y1="-7.62" x2="124.46" y2="-7.62" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND6" gate="1" pin="GND"/>
<pinref part="P1" gate="G$1" pin="4"/>
<wire x1="132.08" y1="-20.32" x2="134.62" y2="-17.78" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="USART2_RX"/>
<wire x1="40.64" y1="-30.48" x2="45.72" y2="-30.48" width="0.1524" layer="91"/>
<wire x1="45.72" y1="-30.48" x2="48.26" y2="-33.02" width="0.1524" layer="91"/>
<wire x1="48.26" y1="-33.02" x2="53.34" y2="-33.02" width="0.1524" layer="91"/>
<wire x1="53.34" y1="-33.02" x2="55.88" y2="-35.56" width="0.1524" layer="91"/>
<pinref part="U$3" gate="G$1" pin="TX"/>
<wire x1="55.88" y1="-35.56" x2="58.42" y2="-35.56" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="USART2_TX"/>
<wire x1="40.64" y1="-33.02" x2="45.72" y2="-33.02" width="0.1524" layer="91"/>
<wire x1="45.72" y1="-33.02" x2="48.26" y2="-30.48" width="0.1524" layer="91"/>
<pinref part="U$3" gate="G$1" pin="RX"/>
<wire x1="48.26" y1="-30.48" x2="58.42" y2="-30.48" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="USB_D+"/>
<wire x1="40.64" y1="-17.78" x2="53.34" y2="-17.78" width="0.1524" layer="91"/>
<wire x1="53.34" y1="-17.78" x2="63.5" y2="-7.62" width="0.1524" layer="91"/>
<pinref part="U$4" gate="G$1" pin="TXD"/>
<wire x1="63.5" y1="-7.62" x2="78.74" y2="-7.62" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="USB_D-"/>
<wire x1="40.64" y1="-20.32" x2="53.34" y2="-20.32" width="0.1524" layer="91"/>
<pinref part="U$4" gate="G$1" pin="RXD"/>
<wire x1="53.34" y1="-20.32" x2="58.42" y2="-15.24" width="0.1524" layer="91"/>
<wire x1="58.42" y1="-15.24" x2="78.74" y2="-15.24" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="U$4" gate="G$1" pin="RS"/>
<pinref part="R1" gate="G$1" pin="1"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="U$4" gate="G$1" pin="CANH"/>
<wire x1="111.76" y1="-10.16" x2="119.38" y2="-10.16" width="0.1524" layer="91"/>
<wire x1="119.38" y1="-10.16" x2="121.92" y2="-12.7" width="0.1524" layer="91"/>
<pinref part="P1" gate="G$1" pin="2"/>
<wire x1="121.92" y1="-12.7" x2="134.62" y2="-12.7" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$9" class="0">
<segment>
<pinref part="P1" gate="G$1" pin="3"/>
<wire x1="134.62" y1="-15.24" x2="121.92" y2="-15.24" width="0.1524" layer="91"/>
<wire x1="121.92" y1="-15.24" x2="119.38" y2="-12.7" width="0.1524" layer="91"/>
<pinref part="U$4" gate="G$1" pin="CANL"/>
<wire x1="119.38" y1="-12.7" x2="111.76" y2="-12.7" width="0.1524" layer="91"/>
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
