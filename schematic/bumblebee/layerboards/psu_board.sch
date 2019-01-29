<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.2.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting keepoldvectorfont="yes"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="11" visible="no" active="no"/>
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
<layer number="51" name="tDocu" color="6" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="99" name="SpiceOrder" color="5" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="battery" urn="urn:adsk.eagle:library:109">
<description>&lt;b&gt;Lithium Batteries and NC Accus&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="SL-160AA/PT" urn="urn:adsk.eagle:footprint:4561/1" library_version="1">
<description>&lt;b&gt;LI BATTERY&lt;/b&gt; Sonnenschein</description>
<wire x1="-25.273" y1="6.858" x2="-25.273" y2="6.985" width="0.1524" layer="21"/>
<wire x1="-25.4" y1="-3.048" x2="-25.4" y2="3.048" width="0.4064" layer="21"/>
<wire x1="22.352" y1="-7.366" x2="-24.892" y2="-7.366" width="0.1524" layer="21"/>
<wire x1="-25.273" y1="-6.985" x2="-25.273" y2="-6.858" width="0.1524" layer="21"/>
<wire x1="25.273" y1="-2.413" x2="25.273" y2="2.413" width="0.4064" layer="51"/>
<wire x1="-25.4" y1="-5.461" x2="-25.4" y2="-3.048" width="0.4064" layer="51"/>
<wire x1="-25.4" y1="3.048" x2="-25.4" y2="5.461" width="0.4064" layer="51"/>
<wire x1="25.019" y1="1.905" x2="25.019" y2="3.556" width="0.1524" layer="21"/>
<wire x1="25.019" y1="-3.556" x2="25.019" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="25.019" y1="3.556" x2="24.13" y2="3.556" width="0.1524" layer="21"/>
<wire x1="24.13" y1="3.556" x2="22.733" y2="6.985" width="0.1524" layer="21"/>
<wire x1="25.019" y1="-3.556" x2="24.13" y2="-3.556" width="0.1524" layer="21"/>
<wire x1="24.13" y1="-3.556" x2="24.13" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="24.13" y1="-1.524" x2="24.13" y2="1.397" width="0.1524" layer="51"/>
<wire x1="24.13" y1="1.397" x2="24.13" y2="3.556" width="0.1524" layer="21"/>
<wire x1="-24.384" y1="0" x2="-22.86" y2="0" width="0.254" layer="21"/>
<wire x1="21.336" y1="-0.762" x2="21.336" y2="0.762" width="0.254" layer="21"/>
<wire x1="20.574" y1="0" x2="22.098" y2="0" width="0.254" layer="21"/>
<wire x1="22.733" y1="-6.985" x2="24.13" y2="-3.556" width="0.1524" layer="21"/>
<wire x1="22.352" y1="7.366" x2="-24.892" y2="7.366" width="0.1524" layer="21"/>
<wire x1="0.635" y1="2.54" x2="0.635" y2="0" width="0.254" layer="21"/>
<wire x1="-2.54" y1="0" x2="-0.635" y2="0" width="0.1524" layer="21"/>
<wire x1="0.635" y1="0" x2="2.54" y2="0" width="0.1524" layer="21"/>
<wire x1="0.635" y1="0" x2="0.635" y2="-2.54" width="0.254" layer="21"/>
<wire x1="1.143" y1="1.524" x2="2.159" y2="1.524" width="0.1524" layer="21"/>
<wire x1="1.651" y1="2.032" x2="1.651" y2="1.016" width="0.1524" layer="21"/>
<wire x1="25.019" y1="-1.905" x2="25.019" y2="1.905" width="0.1524" layer="51"/>
<wire x1="22.733" y1="6.985" x2="22.733" y2="-6.985" width="0.1524" layer="21"/>
<wire x1="-25.273" y1="-6.858" x2="-25.273" y2="-5.461" width="0.1524" layer="51"/>
<wire x1="-25.273" y1="6.858" x2="-25.273" y2="5.461" width="0.1524" layer="51"/>
<wire x1="22.352" y1="-7.366" x2="22.733" y2="-6.985" width="0.1524" layer="21" curve="90"/>
<wire x1="22.352" y1="7.366" x2="22.733" y2="6.985" width="0.1524" layer="21" curve="-90"/>
<wire x1="-25.273" y1="-6.985" x2="-24.892" y2="-7.366" width="0.1524" layer="21" curve="90"/>
<wire x1="-25.273" y1="6.985" x2="-24.892" y2="7.366" width="0.1524" layer="21" curve="-90"/>
<pad name="-" x="-25.4" y="-5.08" drill="1.3208" diameter="3.1496" shape="octagon"/>
<pad name="-@1" x="-25.4" y="5.08" drill="1.3208" diameter="3.1496" shape="octagon"/>
<pad name="+" x="25.273" y="0" drill="1.3208" diameter="3.1496" shape="octagon"/>
<text x="-25.4" y="8.128" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-6.223" y="4.191" size="1.27" layer="21" ratio="10">Lithium 3V</text>
<text x="-5.08" y="-5.715" size="1.27" layer="21" ratio="10">SLAAPT</text>
<text x="-17.78" y="-3.81" size="1.27" layer="27" ratio="10" rot="R90">&gt;VALUE</text>
<rectangle x1="-0.635" y1="-1.27" x2="0" y2="1.27" layer="21"/>
</package>
</packages>
<packages3d>
<package3d name="SL-160AA/PT" urn="urn:adsk.eagle:package:4615/1" type="box" library_version="1">
<description>LI BATTERY Sonnenschein</description>
<packageinstances>
<packageinstance name="SL-160AA/PT"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="1V2-2" urn="urn:adsk.eagle:symbol:4520/1" library_version="1">
<wire x1="0.635" y1="0.635" x2="0.635" y2="0" width="0.4064" layer="94"/>
<wire x1="-2.54" y1="0" x2="0.635" y2="0" width="0.1524" layer="94"/>
<wire x1="0.635" y1="0" x2="0.635" y2="-0.635" width="0.4064" layer="94"/>
<wire x1="1.905" y1="2.54" x2="1.905" y2="0" width="0.4064" layer="94"/>
<wire x1="1.905" y1="0" x2="2.54" y2="0" width="0.1524" layer="94"/>
<wire x1="1.905" y1="0" x2="1.905" y2="-2.54" width="0.4064" layer="94"/>
<text x="0" y="3.175" size="1.778" layer="95">&gt;NAME</text>
<text x="0" y="-5.08" size="1.778" layer="96">&gt;VALUE</text>
<pin name="+" x="5.08" y="0" visible="pad" length="short" direction="pas" rot="R180"/>
<pin name="-" x="-5.08" y="0" visible="pad" length="short" direction="pas"/>
<pin name="-@1" x="-2.54" y="0" visible="off" length="point" direction="pas"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="SL-160AA/PT" urn="urn:adsk.eagle:component:4675/1" prefix="G" library_version="1">
<description>&lt;b&gt;LI BATTERY&lt;/b&gt; Sonnenschein</description>
<gates>
<gate name="G$1" symbol="1V2-2" x="0" y="0"/>
</gates>
<devices>
<device name="" package="SL-160AA/PT">
<connects>
<connect gate="G$1" pin="+" pad="+"/>
<connect gate="G$1" pin="-" pad="-"/>
<connect gate="G$1" pin="-@1" pad="-@1"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:4615/1"/>
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
<library name="dc-dc-converter" urn="urn:adsk.eagle:library:208">
<description>&lt;b&gt;DC-DC Converters&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="NME" urn="urn:adsk.eagle:footprint:12288/1" library_version="1">
<description>&lt;b&gt;DC-DC CONVERTER&lt;/b&gt;</description>
<wire x1="-1.143" y1="5.842" x2="4.953" y2="5.842" width="0.1524" layer="21"/>
<wire x1="4.953" y1="5.842" x2="4.953" y2="-5.842" width="0.1524" layer="21"/>
<wire x1="4.953" y1="-5.842" x2="-1.143" y2="-5.842" width="0.1524" layer="21"/>
<wire x1="-1.143" y1="-5.842" x2="-1.143" y2="-4.572" width="0.1524" layer="21"/>
<wire x1="-1.143" y1="-4.572" x2="-1.143" y2="-3.048" width="0.1524" layer="51"/>
<wire x1="-1.143" y1="4.572" x2="-1.143" y2="5.842" width="0.1524" layer="21"/>
<wire x1="-1.143" y1="-2.032" x2="-1.143" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-1.143" y1="-3.048" x2="-1.143" y2="-2.032" width="0.1524" layer="21"/>
<wire x1="-1.143" y1="-0.508" x2="-1.143" y2="0.508" width="0.1524" layer="21"/>
<wire x1="-1.143" y1="0.508" x2="-1.143" y2="2.032" width="0.1524" layer="51"/>
<wire x1="-1.143" y1="2.032" x2="-1.143" y2="3.048" width="0.1524" layer="21"/>
<wire x1="-1.143" y1="3.048" x2="-1.143" y2="4.572" width="0.1524" layer="51"/>
<circle x="0" y="5.08" radius="0.254" width="0.1524" layer="21"/>
<pad name="1" x="0" y="3.81" drill="0.8128" shape="long"/>
<pad name="2" x="0" y="1.27" drill="0.8128" shape="long"/>
<pad name="3" x="0" y="-1.27" drill="0.8128" shape="long"/>
<pad name="4" x="0" y="-3.81" drill="0.8128" shape="long"/>
<text x="-1.143" y="6.223" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="3.048" y="-5.08" size="1.27" layer="27" ratio="10" rot="R90">&gt;VALUE</text>
<text x="4.572" y="-5.08" size="1.016" layer="21" ratio="12" rot="R90">DC-DC</text>
</package>
</packages>
<packages3d>
<package3d name="NME" urn="urn:adsk.eagle:package:12313/1" type="box" library_version="1">
<description>DC-DC CONVERTER</description>
<packageinstances>
<packageinstance name="NME"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="DC+" urn="urn:adsk.eagle:symbol:12287/1" library_version="1">
<wire x1="-10.16" y1="5.08" x2="10.16" y2="5.08" width="0.4064" layer="94"/>
<wire x1="10.16" y1="5.08" x2="10.16" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="10.16" y1="-7.62" x2="-10.16" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="-10.16" y1="-7.62" x2="-10.16" y2="5.08" width="0.4064" layer="94"/>
<text x="-10.16" y="5.715" size="1.778" layer="95">&gt;NAME</text>
<text x="-10.16" y="-10.16" size="1.778" layer="96">&gt;VALUE</text>
<text x="-8.636" y="-6.731" size="1.27" layer="94">DC/DC CONVERTER</text>
<pin name="+VIN" x="-12.7" y="2.54" length="short" direction="pas"/>
<pin name="-VIN" x="-12.7" y="-2.54" length="short" direction="pas"/>
<pin name="+VOUT" x="12.7" y="2.54" length="short" direction="pas" rot="R180"/>
<pin name="-VOUT" x="12.7" y="-2.54" length="short" direction="pas" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="NME" urn="urn:adsk.eagle:component:12326/1" prefix="DC" uservalue="yes" library_version="1">
<description>&lt;b&gt;DC-DC CONVERTER&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="DC+" x="0" y="0"/>
</gates>
<devices>
<device name="" package="NME">
<connects>
<connect gate="G$1" pin="+VIN" pad="2"/>
<connect gate="G$1" pin="+VOUT" pad="4"/>
<connect gate="G$1" pin="-VIN" pad="1"/>
<connect gate="G$1" pin="-VOUT" pad="3"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:12313/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="C &amp; D TECHNOLOGIES, INC" constant="no"/>
<attribute name="MPN" value="NME1205D" constant="no"/>
<attribute name="OC_FARNELL" value="1021466" constant="no"/>
<attribute name="OC_NEWARK" value="98B8198" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="transistor-power" urn="urn:adsk.eagle:library:400">
<description>&lt;b&gt;Power Transistors&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="TO220BV" urn="urn:adsk.eagle:footprint:29371/1" library_version="2">
<description>&lt;b&gt;Molded Package&lt;/b&gt;&lt;p&gt;
grid 2.54 mm</description>
<wire x1="4.699" y1="-4.318" x2="4.953" y2="-4.064" width="0.1524" layer="21"/>
<wire x1="4.699" y1="-4.318" x2="-4.699" y2="-4.318" width="0.1524" layer="21"/>
<wire x1="-4.953" y1="-4.064" x2="-4.699" y2="-4.318" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-1.143" x2="4.953" y2="-4.064" width="0.1524" layer="21"/>
<wire x1="-4.953" y1="-4.064" x2="-5.08" y2="-1.143" width="0.1524" layer="21"/>
<circle x="-4.4958" y="-3.7084" radius="0.254" width="0" layer="21"/>
<pad name="G" x="-2.54" y="-2.54" drill="1.016" shape="long" rot="R90"/>
<pad name="D" x="0" y="-2.54" drill="1.016" shape="long" rot="R90"/>
<pad name="S" x="2.54" y="-2.54" drill="1.016" shape="long" rot="R90"/>
<text x="-5.08" y="-6.0452" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-5.08" y="-7.62" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<rectangle x1="-5.334" y1="-0.762" x2="5.334" y2="0" layer="21"/>
<rectangle x1="-5.334" y1="-1.27" x2="-3.429" y2="-0.762" layer="21"/>
<rectangle x1="-1.651" y1="-1.27" x2="-0.889" y2="-0.762" layer="21"/>
<rectangle x1="-3.429" y1="-1.27" x2="-1.651" y2="-0.762" layer="51"/>
<rectangle x1="0.889" y1="-1.27" x2="1.651" y2="-0.762" layer="21"/>
<rectangle x1="3.429" y1="-1.27" x2="5.334" y2="-0.762" layer="21"/>
<rectangle x1="-0.889" y1="-1.27" x2="0.889" y2="-0.762" layer="51"/>
<rectangle x1="1.651" y1="-1.27" x2="3.429" y2="-0.762" layer="51"/>
</package>
</packages>
<packages3d>
<package3d name="TO220BV" urn="urn:adsk.eagle:package:29484/3" type="model" library_version="2">
<description>Molded Package
grid 2.54 mm</description>
<packageinstances>
<packageinstance name="TO220BV"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="MFPD" urn="urn:adsk.eagle:symbol:29378/1" library_version="2">
<wire x1="3.81" y1="1.905" x2="2.54" y2="1.905" width="0.1524" layer="94"/>
<wire x1="3.81" y1="1.905" x2="3.81" y2="0.762" width="0.1524" layer="94"/>
<wire x1="3.81" y1="0.762" x2="3.81" y2="-1.905" width="0.1524" layer="94"/>
<wire x1="3.81" y1="0.762" x2="4.445" y2="-0.635" width="0.1524" layer="94"/>
<wire x1="4.445" y1="-0.635" x2="3.175" y2="-0.635" width="0.1524" layer="94"/>
<wire x1="3.175" y1="-0.635" x2="3.81" y2="0.762" width="0.1524" layer="94"/>
<wire x1="4.445" y1="0.762" x2="3.81" y2="0.762" width="0.1524" layer="94"/>
<wire x1="3.81" y1="0.762" x2="3.175" y2="0.762" width="0.1524" layer="94"/>
<wire x1="3.175" y1="0.762" x2="2.921" y2="1.016" width="0.1524" layer="94"/>
<wire x1="4.445" y1="0.762" x2="4.699" y2="0.508" width="0.1524" layer="94"/>
<wire x1="-1.016" y1="-2.54" x2="-1.016" y2="2.54" width="0.254" layer="94"/>
<wire x1="3.81" y1="-1.905" x2="2.54" y2="-1.905" width="0.1524" layer="94"/>
<wire x1="2.54" y1="-1.905" x2="0.5334" y2="-1.905" width="0.1524" layer="94"/>
<wire x1="2.54" y1="-2.54" x2="2.54" y2="-1.905" width="0.1524" layer="94"/>
<wire x1="2.2352" y1="0" x2="2.286" y2="0" width="0.1524" layer="94"/>
<wire x1="2.286" y1="0" x2="2.54" y2="0" width="0.1524" layer="94"/>
<wire x1="2.54" y1="2.54" x2="2.54" y2="1.905" width="0.1524" layer="94"/>
<wire x1="2.54" y1="1.905" x2="0.508" y2="1.905" width="0.1524" layer="94"/>
<wire x1="-1.016" y1="-2.54" x2="-2.54" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="2.286" y1="0" x2="1.016" y2="-0.508" width="0.1524" layer="94"/>
<wire x1="1.016" y1="-0.508" x2="1.016" y2="0.508" width="0.1524" layer="94"/>
<wire x1="1.016" y1="0.508" x2="2.286" y2="0" width="0.1524" layer="94"/>
<wire x1="1.143" y1="0" x2="0.254" y2="0" width="0.1524" layer="94"/>
<wire x1="1.143" y1="0.254" x2="2.032" y2="0" width="0.3048" layer="94"/>
<wire x1="2.032" y1="0" x2="1.143" y2="-0.254" width="0.3048" layer="94"/>
<wire x1="1.143" y1="-0.254" x2="1.143" y2="0" width="0.3048" layer="94"/>
<wire x1="1.143" y1="0" x2="1.397" y2="0" width="0.3048" layer="94"/>
<wire x1="2.54" y1="0" x2="2.54" y2="1.905" width="0.1524" layer="94"/>
<circle x="2.54" y="-1.905" radius="0.127" width="0.4064" layer="94"/>
<circle x="2.54" y="1.905" radius="0.127" width="0.4064" layer="94"/>
<text x="5.08" y="2.54" size="1.778" layer="95">&gt;NAME</text>
<text x="5.08" y="0" size="1.778" layer="96">&gt;VALUE</text>
<text x="1.524" y="-3.302" size="0.8128" layer="93">D</text>
<text x="1.524" y="2.54" size="0.8128" layer="93">S</text>
<text x="-2.54" y="-2.032" size="0.8128" layer="93">G</text>
<rectangle x1="-0.254" y1="1.27" x2="0.508" y2="2.54" layer="94"/>
<rectangle x1="-0.254" y1="-2.54" x2="0.508" y2="-1.27" layer="94"/>
<rectangle x1="-0.254" y1="-0.889" x2="0.508" y2="0.889" layer="94"/>
<pin name="G" x="-5.08" y="-2.54" visible="off" length="short" direction="pas"/>
<pin name="D" x="2.54" y="-5.08" visible="off" length="short" direction="pas" rot="R90"/>
<pin name="S" x="2.54" y="5.08" visible="off" length="short" direction="pas" rot="R270"/>
</symbol>
<symbol name="MFNS" urn="urn:adsk.eagle:symbol:29370/1" library_version="2">
<wire x1="-1.1176" y1="2.413" x2="-1.1176" y2="-2.54" width="0.254" layer="94"/>
<wire x1="-1.1176" y1="-2.54" x2="-2.54" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="2.54" y1="1.905" x2="0.5334" y2="1.905" width="0.1524" layer="94"/>
<wire x1="2.54" y1="0" x2="2.54" y2="-1.905" width="0.1524" layer="94"/>
<wire x1="0.508" y1="-1.905" x2="2.54" y2="-1.905" width="0.1524" layer="94"/>
<wire x1="2.54" y1="2.54" x2="2.54" y2="1.905" width="0.1524" layer="94"/>
<wire x1="2.54" y1="1.905" x2="5.08" y2="1.905" width="0.1524" layer="94"/>
<wire x1="5.08" y1="1.905" x2="5.08" y2="0.762" width="0.1524" layer="94"/>
<wire x1="5.08" y1="0.762" x2="5.08" y2="-1.905" width="0.1524" layer="94"/>
<wire x1="5.08" y1="-1.905" x2="2.54" y2="-1.905" width="0.1524" layer="94"/>
<wire x1="2.54" y1="-1.905" x2="2.54" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="5.08" y1="0.762" x2="4.445" y2="-0.635" width="0.1524" layer="94"/>
<wire x1="4.445" y1="-0.635" x2="5.715" y2="-0.635" width="0.1524" layer="94"/>
<wire x1="5.715" y1="-0.635" x2="5.08" y2="0.762" width="0.1524" layer="94"/>
<wire x1="4.445" y1="0.762" x2="5.08" y2="0.762" width="0.1524" layer="94"/>
<wire x1="5.08" y1="0.762" x2="5.715" y2="0.762" width="0.1524" layer="94"/>
<wire x1="5.715" y1="0.762" x2="5.969" y2="1.016" width="0.1524" layer="94"/>
<wire x1="4.445" y1="0.762" x2="4.191" y2="0.508" width="0.1524" layer="94"/>
<wire x1="0.508" y1="0" x2="1.778" y2="-0.508" width="0.1524" layer="94"/>
<wire x1="1.778" y1="-0.508" x2="1.778" y2="0.508" width="0.1524" layer="94"/>
<wire x1="1.778" y1="0.508" x2="0.508" y2="0" width="0.1524" layer="94"/>
<wire x1="1.651" y1="0" x2="2.54" y2="0" width="0.1524" layer="94"/>
<wire x1="1.651" y1="0.254" x2="0.762" y2="0" width="0.3048" layer="94"/>
<wire x1="0.762" y1="0" x2="1.651" y2="-0.254" width="0.3048" layer="94"/>
<wire x1="1.651" y1="-0.254" x2="1.651" y2="0" width="0.3048" layer="94"/>
<wire x1="1.651" y1="0" x2="1.397" y2="0" width="0.3048" layer="94"/>
<circle x="2.54" y="-1.905" radius="0.127" width="0.4064" layer="94"/>
<circle x="2.54" y="1.905" radius="0.127" width="0.4064" layer="94"/>
<text x="7.62" y="2.54" size="1.778" layer="95">&gt;NAME</text>
<text x="7.62" y="0" size="1.778" layer="96">&gt;VALUE</text>
<text x="1.27" y="2.54" size="0.8128" layer="93">D</text>
<text x="1.27" y="-3.175" size="0.8128" layer="93">S</text>
<text x="-2.54" y="-1.27" size="0.8128" layer="93">G</text>
<rectangle x1="-0.254" y1="-2.54" x2="0.508" y2="-1.27" layer="94"/>
<rectangle x1="-0.254" y1="1.27" x2="0.508" y2="2.54" layer="94"/>
<rectangle x1="-0.254" y1="-0.889" x2="0.508" y2="0.889" layer="94"/>
<pin name="G" x="-2.54" y="-2.54" visible="off" length="point" direction="pas"/>
<pin name="D" x="2.54" y="5.08" visible="off" length="short" direction="pas" rot="R270"/>
<pin name="S" x="2.54" y="-5.08" visible="off" length="short" direction="pas" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="IRF9530" urn="urn:adsk.eagle:component:29544/3" prefix="Q" library_version="2">
<description>&lt;b&gt;P-CHANNEL HEXFET POWER-MOS-FET&lt;/b&gt;&lt;p&gt;
Source: http://www.irf.com/product-info/datasheets/data/irf9530.pdf</description>
<gates>
<gate name="G$1" symbol="MFPD" x="0" y="0"/>
</gates>
<devices>
<device name="" package="TO220BV">
<connects>
<connect gate="G$1" pin="D" pad="D"/>
<connect gate="G$1" pin="G" pad="G"/>
<connect gate="G$1" pin="S" pad="S"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:29484/3"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="IRF540" urn="urn:adsk.eagle:component:29540/3" prefix="Q" library_version="2">
<description>&lt;b&gt;HEXFET Power MOSFET&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="MFNS" x="0" y="0"/>
</gates>
<devices>
<device name="" package="TO220BV">
<connects>
<connect gate="G$1" pin="D" pad="D"/>
<connect gate="G$1" pin="G" pad="G"/>
<connect gate="G$1" pin="S" pad="S"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:29484/3"/>
</package3dinstances>
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
<package name="CHARGER">
<wire x1="-19.05" y1="3.81" x2="-19.05" y2="-3.81" width="0.127" layer="21"/>
<wire x1="-19.05" y1="-3.81" x2="19.05" y2="-3.81" width="0.127" layer="21"/>
<wire x1="19.05" y1="-3.81" x2="19.05" y2="3.81" width="0.127" layer="21"/>
<wire x1="19.05" y1="3.81" x2="-19.05" y2="3.81" width="0.127" layer="21"/>
<pad name="P-" x="-16.51" y="0" drill="0.6" shape="square" rot="R180"/>
<pad name="P+" x="16.51" y="0" drill="0.6" shape="square"/>
<pad name="B-" x="-11.43" y="-2.54" drill="0.6" shape="square"/>
<pad name="BALANCE" x="0" y="-2.54" drill="0.6" shape="square"/>
<pad name="B+" x="11.43" y="-2.54" drill="0.6" shape="square"/>
<text x="-3.81" y="-1.27" size="1.27" layer="21">REDRAW
</text>
</package>
<package name="INA">
<rectangle x1="-12.5" y1="-11.2" x2="12.5" y2="11.2" layer="21"/>
<hole x="-10.5" y="9.2" drill="3"/>
<hole x="10.5" y="9.2" drill="3"/>
<hole x="10.5" y="-9.2" drill="3"/>
<hole x="-10.5" y="-9.2" drill="3"/>
<pad name="SDA" x="0.93" y="-8.7" drill="0.8" shape="square" rot="R180"/>
<pad name="SCL" x="-1.61" y="-8.7" drill="0.8" shape="square"/>
<pad name="GND" x="-4.15" y="-8.7" drill="0.8" shape="square"/>
<pad name="VCC" x="-6.72" y="-8.7" drill="0.8" shape="square"/>
<pad name="VIN-_0" x="3.47" y="-8.7" drill="0.8" shape="square"/>
<pad name="VIN+_0" x="6.04" y="-8.7" drill="0.8" shape="square"/>
<pad name="VIN+_1" x="1.27" y="7.7" drill="0.8" shape="square"/>
<pad name="VIN-_1" x="-1.27" y="7.7" drill="0.8" shape="square" rot="R90"/>
<dimension x1="-12.5" y1="11.2" x2="12.5" y2="11.2" x3="0" y3="19.85" textsize="1.27" layer="17"/>
<dimension x1="-12.5" y1="-11.2" x2="-12.5" y2="11.2" x3="-25.44" y3="0" textsize="1.27" layer="17"/>
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
<symbol name="CHARGER">
<wire x1="-12.7" y1="10.16" x2="12.7" y2="10.16" width="0.254" layer="94"/>
<wire x1="12.7" y1="10.16" x2="12.7" y2="-5.08" width="0.254" layer="94"/>
<wire x1="12.7" y1="-5.08" x2="-12.7" y2="-5.08" width="0.254" layer="94"/>
<wire x1="-12.7" y1="-5.08" x2="-12.7" y2="10.16" width="0.254" layer="94"/>
<pin name="BALANCE" x="0" y="-10.16" length="middle" rot="R90"/>
<pin name="B-" x="-7.62" y="-10.16" length="middle" rot="R90"/>
<pin name="B+" x="7.62" y="-10.16" length="middle" rot="R90"/>
<pin name="P-" x="-5.08" y="15.24" length="middle" rot="R270"/>
<pin name="P+" x="5.08" y="15.24" length="middle" rot="R270"/>
</symbol>
<symbol name="INA">
<pin name="VIN-" x="12.7" y="5.08" length="middle" rot="R180"/>
<pin name="VIN+" x="-12.7" y="5.08" length="middle"/>
<pin name="SDA" x="12.7" y="-5.08" length="middle" rot="R180"/>
<pin name="SCL" x="12.7" y="0" length="middle" rot="R180"/>
<pin name="GND" x="-12.7" y="0" length="middle"/>
<pin name="VCC" x="-12.7" y="-5.08" length="middle"/>
<wire x1="7.62" y1="7.62" x2="-7.62" y2="7.62" width="0.254" layer="94"/>
<wire x1="-7.62" y1="7.62" x2="-7.62" y2="-7.62" width="0.254" layer="94"/>
<wire x1="-7.62" y1="-7.62" x2="7.62" y2="-7.62" width="0.254" layer="94"/>
<wire x1="7.62" y1="7.62" x2="7.62" y2="-7.62" width="0.254" layer="94"/>
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
<deviceset name="CHARGER">
<gates>
<gate name="G$1" symbol="CHARGER" x="0" y="-2.54"/>
</gates>
<devices>
<device name="" package="CHARGER">
<connects>
<connect gate="G$1" pin="B+" pad="B+"/>
<connect gate="G$1" pin="B-" pad="B-"/>
<connect gate="G$1" pin="BALANCE" pad="BALANCE"/>
<connect gate="G$1" pin="P+" pad="P+"/>
<connect gate="G$1" pin="P-" pad="P-"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="INA">
<gates>
<gate name="G$1" symbol="INA" x="0" y="0"/>
</gates>
<devices>
<device name="" package="INA">
<connects>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="SCL" pad="SCL"/>
<connect gate="G$1" pin="SDA" pad="SDA"/>
<connect gate="G$1" pin="VCC" pad="VCC"/>
<connect gate="G$1" pin="VIN+" pad="VIN+_0 VIN+_1"/>
<connect gate="G$1" pin="VIN-" pad="VIN-_0 VIN-_1"/>
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
<library name="diode" urn="urn:adsk.eagle:library:210">
<description>&lt;b&gt;Diodes&lt;/b&gt;&lt;p&gt;
Based on the following sources:
&lt;ul&gt;
&lt;li&gt;Motorola : www.onsemi.com
&lt;li&gt;Fairchild : www.fairchildsemi.com
&lt;li&gt;Philips : www.semiconductors.com
&lt;li&gt;Vishay : www.vishay.de
&lt;/ul&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="DO35-10" urn="urn:adsk.eagle:footprint:43092/1" library_version="2">
<description>&lt;B&gt;DIODE&lt;/B&gt;&lt;p&gt;
diameter 2 mm, horizontal, grid 10.16 mm</description>
<wire x1="5.08" y1="0" x2="4.191" y2="0" width="0.508" layer="51"/>
<wire x1="-5.08" y1="0" x2="-4.191" y2="0" width="0.508" layer="51"/>
<wire x1="-0.635" y1="0" x2="0" y2="0" width="0.1524" layer="21"/>
<wire x1="1.016" y1="0.635" x2="1.016" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="1.016" y1="-0.635" x2="0" y2="0" width="0.1524" layer="21"/>
<wire x1="0" y1="0" x2="1.524" y2="0" width="0.1524" layer="21"/>
<wire x1="0" y1="0" x2="1.016" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="0" y2="0" width="0.1524" layer="21"/>
<wire x1="0" y1="0" x2="0" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="2.032" y1="1.016" x2="2.286" y2="0.762" width="0.1524" layer="21" curve="-90"/>
<wire x1="-2.286" y1="0.762" x2="-2.032" y2="1.016" width="0.1524" layer="21" curve="-90"/>
<wire x1="-2.286" y1="-0.762" x2="-2.032" y2="-1.016" width="0.1524" layer="21" curve="90"/>
<wire x1="2.032" y1="-1.016" x2="2.286" y2="-0.762" width="0.1524" layer="21" curve="90"/>
<wire x1="2.286" y1="-0.762" x2="2.286" y2="0.762" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="0.762" x2="-2.286" y2="-0.762" width="0.1524" layer="21"/>
<wire x1="-2.032" y1="1.016" x2="2.032" y2="1.016" width="0.1524" layer="21"/>
<wire x1="-2.032" y1="-1.016" x2="2.032" y2="-1.016" width="0.1524" layer="21"/>
<pad name="C" x="-5.08" y="0" drill="0.8128" shape="long"/>
<pad name="A" x="5.08" y="0" drill="0.8128" shape="long"/>
<text x="-2.159" y="1.27" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-2.159" y="-2.667" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<rectangle x1="-1.905" y1="-1.016" x2="-1.397" y2="1.016" layer="21"/>
<rectangle x1="2.286" y1="-0.254" x2="4.191" y2="0.254" layer="21"/>
<rectangle x1="-4.191" y1="-0.254" x2="-2.286" y2="0.254" layer="21"/>
</package>
</packages>
<packages3d>
<package3d name="DO35-10" urn="urn:adsk.eagle:package:43344/2" type="model" library_version="2">
<description>DIODE
diameter 2 mm, horizontal, grid 10.16 mm</description>
<packageinstances>
<packageinstance name="DO35-10"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="D" urn="urn:adsk.eagle:symbol:43091/1" library_version="2">
<wire x1="-1.27" y1="-1.27" x2="1.27" y2="0" width="0.254" layer="94"/>
<wire x1="1.27" y1="0" x2="-1.27" y2="1.27" width="0.254" layer="94"/>
<wire x1="1.27" y1="1.27" x2="1.27" y2="0" width="0.254" layer="94"/>
<wire x1="-1.27" y1="1.27" x2="-1.27" y2="-1.27" width="0.254" layer="94"/>
<wire x1="1.27" y1="0" x2="1.27" y2="-1.27" width="0.254" layer="94"/>
<text x="2.54" y="0.4826" size="1.778" layer="95">&gt;NAME</text>
<text x="2.54" y="-2.3114" size="1.778" layer="96">&gt;VALUE</text>
<text x="-2.54" y="0" size="0.4064" layer="99" align="center">SpiceOrder 1</text>
<text x="2.54" y="0" size="0.4064" layer="99" align="center">SpiceOrder 2</text>
<pin name="A" x="-2.54" y="0" visible="off" length="short" direction="pas"/>
<pin name="C" x="2.54" y="0" visible="off" length="short" direction="pas" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="1N4446" urn="urn:adsk.eagle:component:43503/2" prefix="D" library_version="2">
<description>&lt;B&gt;DIODE&lt;/B&gt;&lt;p&gt;
high speed (Philips)</description>
<gates>
<gate name="1" symbol="D" x="0" y="0"/>
</gates>
<devices>
<device name="" package="DO35-10">
<connects>
<connect gate="1" pin="A" pad="A"/>
<connect gate="1" pin="C" pad="C"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:43344/2"/>
</package3dinstances>
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
<part name="G1" library="battery" library_urn="urn:adsk.eagle:library:109" deviceset="SL-160AA/PT" device="" package3d_urn="urn:adsk.eagle:package:4615/1"/>
<part name="DC1" library="dc-dc-converter" library_urn="urn:adsk.eagle:library:208" deviceset="NME" device="" package3d_urn="urn:adsk.eagle:package:12313/1"/>
<part name="GND4" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="DC2" library="dc-dc-converter" library_urn="urn:adsk.eagle:library:208" deviceset="NME" device="" package3d_urn="urn:adsk.eagle:package:12313/1"/>
<part name="GND5" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="DC3" library="dc-dc-converter" library_urn="urn:adsk.eagle:library:208" deviceset="NME" device="" package3d_urn="urn:adsk.eagle:package:12313/1"/>
<part name="GND6" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="Q1" library="transistor-power" library_urn="urn:adsk.eagle:library:400" deviceset="IRF9530" device="" package3d_urn="urn:adsk.eagle:package:29484/3"/>
<part name="R1" library="ngspice-simulation" library_urn="urn:adsk.eagle:library:527439" deviceset="R" device="" value="10k"/>
<part name="Q2" library="transistor-power" library_urn="urn:adsk.eagle:library:400" deviceset="IRF540" device="" package3d_urn="urn:adsk.eagle:package:29484/3"/>
<part name="R2" library="ngspice-simulation" library_urn="urn:adsk.eagle:library:527439" deviceset="R" device="" value="10k"/>
<part name="GND1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="Q3" library="transistor-power" library_urn="urn:adsk.eagle:library:400" deviceset="IRF9530" device="" package3d_urn="urn:adsk.eagle:package:29484/3"/>
<part name="R3" library="ngspice-simulation" library_urn="urn:adsk.eagle:library:527439" deviceset="R" device="" value="10k"/>
<part name="Q4" library="transistor-power" library_urn="urn:adsk.eagle:library:400" deviceset="IRF540" device="" package3d_urn="urn:adsk.eagle:package:29484/3"/>
<part name="R4" library="ngspice-simulation" library_urn="urn:adsk.eagle:library:527439" deviceset="R" device="" value="10k"/>
<part name="Q5" library="transistor-power" library_urn="urn:adsk.eagle:library:400" deviceset="IRF9530" device="" package3d_urn="urn:adsk.eagle:package:29484/3"/>
<part name="R5" library="ngspice-simulation" library_urn="urn:adsk.eagle:library:527439" deviceset="R" device="" value="10k"/>
<part name="Q6" library="transistor-power" library_urn="urn:adsk.eagle:library:400" deviceset="IRF540" device="" package3d_urn="urn:adsk.eagle:package:29484/3"/>
<part name="R6" library="ngspice-simulation" library_urn="urn:adsk.eagle:library:527439" deviceset="R" device="" value="10k"/>
<part name="Q7" library="transistor-power" library_urn="urn:adsk.eagle:library:400" deviceset="IRF9530" device="" package3d_urn="urn:adsk.eagle:package:29484/3"/>
<part name="R7" library="ngspice-simulation" library_urn="urn:adsk.eagle:library:527439" deviceset="R" device="" value="10k"/>
<part name="Q8" library="transistor-power" library_urn="urn:adsk.eagle:library:400" deviceset="IRF540" device="" package3d_urn="urn:adsk.eagle:package:29484/3"/>
<part name="R8" library="ngspice-simulation" library_urn="urn:adsk.eagle:library:527439" deviceset="R" device="" value="10k"/>
<part name="U$1" library="bluepill" deviceset="BLUEPILL" device="THEONLYONE"/>
<part name="GND2" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="U$4" library="MCP2551" deviceset="MCP2551" device=""/>
<part name="GND9" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="R9" library="ngspice-simulation" library_urn="urn:adsk.eagle:library:527439" deviceset="R" device=""/>
<part name="GND10" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="G2" library="battery" library_urn="urn:adsk.eagle:library:109" deviceset="SL-160AA/PT" device="" package3d_urn="urn:adsk.eagle:package:4615/1"/>
<part name="U$5" library="USB_pcb_connectors" deviceset="PCB_USB_C" device="DS_5"/>
<part name="DC4" library="dc-dc-converter" library_urn="urn:adsk.eagle:library:208" deviceset="NME" device="" package3d_urn="urn:adsk.eagle:package:12313/1"/>
<part name="U$7" library="bluepill" deviceset="CHARGER" device=""/>
<part name="Q9" library="transistor-power" library_urn="urn:adsk.eagle:library:400" deviceset="IRF540" device="" package3d_urn="urn:adsk.eagle:package:29484/3"/>
<part name="GND3" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="R10" library="ngspice-simulation" library_urn="urn:adsk.eagle:library:527439" deviceset="R" device="" value="82k"/>
<part name="R11" library="ngspice-simulation" library_urn="urn:adsk.eagle:library:527439" deviceset="R" device="" value="8.2k"/>
<part name="D1" library="diode" library_urn="urn:adsk.eagle:library:210" deviceset="1N4446" device="" package3d_urn="urn:adsk.eagle:package:43344/2"/>
<part name="D2" library="diode" library_urn="urn:adsk.eagle:library:210" deviceset="1N4446" device="" package3d_urn="urn:adsk.eagle:package:43344/2"/>
<part name="D3" library="diode" library_urn="urn:adsk.eagle:library:210" deviceset="1N4446" device="" package3d_urn="urn:adsk.eagle:package:43344/2"/>
<part name="D4" library="diode" library_urn="urn:adsk.eagle:library:210" deviceset="1N4446" device="" package3d_urn="urn:adsk.eagle:package:43344/2"/>
<part name="U$2" library="bluepill" deviceset="INA" device=""/>
<part name="GND7" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="U$3" library="bluepill" deviceset="INA" device=""/>
<part name="GND8" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="U$8" library="bluepill" deviceset="INA" device=""/>
<part name="GND11" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="U$9" library="bluepill" deviceset="INA" device=""/>
<part name="GND12" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="R12" library="ngspice-simulation" library_urn="urn:adsk.eagle:library:527439" deviceset="R" device="" value="26k"/>
<part name="GND13" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="R13" library="ngspice-simulation" library_urn="urn:adsk.eagle:library:527439" deviceset="R" device="" value="26k"/>
<part name="P1" library="con-jst-eh" deviceset="B5B-EH-A" device=""/>
<part name="GND14" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="P2" library="con-jst-eh" deviceset="B5B-EH-A" device=""/>
<part name="P3" library="con-jst-eh" deviceset="B3B-EH-A" device=""/>
<part name="P4" library="con-jst-eh" deviceset="B4B-EH-A" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="G1" gate="G$1" x="-83.82" y="-55.88" smashed="yes">
<attribute name="NAME" x="-83.82" y="-52.705" size="1.778" layer="95"/>
</instance>
<instance part="DC1" gate="G$1" x="-40.64" y="7.62" smashed="yes">
<attribute name="NAME" x="-50.8" y="13.335" size="1.778" layer="95"/>
<attribute name="VALUE" x="-50.8" y="-2.54" size="1.778" layer="96"/>
</instance>
<instance part="GND4" gate="1" x="-40.64" y="-5.08" smashed="yes">
<attribute name="VALUE" x="-43.18" y="-7.62" size="1.778" layer="96"/>
</instance>
<instance part="DC2" gate="G$1" x="-40.64" y="-15.24" smashed="yes">
<attribute name="NAME" x="-50.8" y="-9.525" size="1.778" layer="95"/>
<attribute name="VALUE" x="-50.8" y="-25.4" size="1.778" layer="96"/>
</instance>
<instance part="GND5" gate="1" x="-40.64" y="-27.94" smashed="yes">
<attribute name="VALUE" x="-43.18" y="-30.48" size="1.778" layer="96"/>
</instance>
<instance part="DC3" gate="G$1" x="-40.64" y="-38.1" smashed="yes">
<attribute name="NAME" x="-50.8" y="-32.385" size="1.778" layer="95"/>
<attribute name="VALUE" x="-50.8" y="-48.26" size="1.778" layer="96"/>
</instance>
<instance part="GND6" gate="1" x="-40.64" y="-50.8" smashed="yes">
<attribute name="VALUE" x="-43.18" y="-53.34" size="1.778" layer="96"/>
</instance>
<instance part="Q1" gate="G$1" x="7.62" y="38.1" smashed="yes">
<attribute name="NAME" x="12.7" y="40.64" size="1.778" layer="95"/>
<attribute name="VALUE" x="12.7" y="38.1" size="1.778" layer="96"/>
</instance>
<instance part="R1" gate="G$1" x="2.54" y="40.64" smashed="yes" rot="R90">
<attribute name="NAME" x="0" y="38.1" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="6.35" y="38.1" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="Q2" gate="G$1" x="0" y="30.48" smashed="yes">
<attribute name="NAME" x="7.62" y="33.02" size="1.778" layer="95"/>
<attribute name="VALUE" x="7.62" y="30.48" size="1.778" layer="96"/>
</instance>
<instance part="R2" gate="G$1" x="-5.08" y="33.02" smashed="yes" rot="R90">
<attribute name="NAME" x="-7.62" y="30.48" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="-1.27" y="30.48" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="GND1" gate="1" x="2.54" y="22.86" smashed="yes">
<attribute name="VALUE" x="0" y="20.32" size="1.778" layer="96"/>
</instance>
<instance part="Q3" gate="G$1" x="7.62" y="10.16" smashed="yes">
<attribute name="NAME" x="12.7" y="12.7" size="1.778" layer="95"/>
<attribute name="VALUE" x="12.7" y="10.16" size="1.778" layer="96"/>
</instance>
<instance part="R3" gate="G$1" x="2.54" y="12.7" smashed="yes" rot="R90">
<attribute name="NAME" x="0" y="10.16" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="6.35" y="10.16" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="Q4" gate="G$1" x="0" y="2.54" smashed="yes">
<attribute name="NAME" x="7.62" y="2.54" size="1.778" layer="95"/>
<attribute name="VALUE" x="7.62" y="0" size="1.778" layer="96"/>
</instance>
<instance part="R4" gate="G$1" x="-5.08" y="5.08" smashed="yes" rot="R90">
<attribute name="NAME" x="-7.62" y="2.54" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="-1.27" y="2.54" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="Q5" gate="G$1" x="7.62" y="-12.7" smashed="yes">
<attribute name="NAME" x="12.7" y="-10.16" size="1.778" layer="95"/>
<attribute name="VALUE" x="12.7" y="-12.7" size="1.778" layer="96"/>
</instance>
<instance part="R5" gate="G$1" x="2.54" y="-10.16" smashed="yes" rot="R90">
<attribute name="NAME" x="0" y="-12.7" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="6.35" y="-12.7" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="Q6" gate="G$1" x="0" y="-20.32" smashed="yes">
<attribute name="NAME" x="7.62" y="-20.32" size="1.778" layer="95"/>
<attribute name="VALUE" x="7.62" y="-22.86" size="1.778" layer="96"/>
</instance>
<instance part="R6" gate="G$1" x="-5.08" y="-17.78" smashed="yes" rot="R90">
<attribute name="NAME" x="-7.62" y="-20.32" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="-1.27" y="-20.32" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="Q7" gate="G$1" x="7.62" y="-35.56" smashed="yes">
<attribute name="NAME" x="12.7" y="-33.02" size="1.778" layer="95"/>
<attribute name="VALUE" x="12.7" y="-35.56" size="1.778" layer="96"/>
</instance>
<instance part="R7" gate="G$1" x="2.54" y="-33.02" smashed="yes" rot="R90">
<attribute name="NAME" x="0" y="-35.56" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="6.35" y="-35.56" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="Q8" gate="G$1" x="0" y="-43.18" smashed="yes">
<attribute name="NAME" x="7.62" y="-43.18" size="1.778" layer="95"/>
<attribute name="VALUE" x="7.62" y="-45.72" size="1.778" layer="96"/>
</instance>
<instance part="R8" gate="G$1" x="-5.08" y="-40.64" smashed="yes" rot="R90">
<attribute name="NAME" x="-7.62" y="-43.18" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="-1.27" y="-43.18" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="U$1" gate="G$1" x="99.06" y="-2.54" smashed="yes">
<attribute name="NAME" x="109.22" y="48.26" size="1.27" layer="95"/>
<attribute name="VALUE" x="109.22" y="45.72" size="1.27" layer="96"/>
</instance>
<instance part="GND2" gate="1" x="132.08" y="38.1" smashed="yes">
<attribute name="VALUE" x="129.54" y="35.56" size="1.778" layer="96"/>
</instance>
<instance part="U$4" gate="G$1" x="172.72" y="-33.02" smashed="yes"/>
<instance part="GND9" gate="1" x="144.78" y="-33.02" smashed="yes">
<attribute name="VALUE" x="142.24" y="-35.56" size="1.778" layer="96"/>
</instance>
<instance part="R9" gate="G$1" x="203.2" y="-30.48" smashed="yes">
<attribute name="NAME" x="200.66" y="-27.94" size="1.778" layer="95"/>
<attribute name="VALUE" x="200.66" y="-34.29" size="1.778" layer="96"/>
</instance>
<instance part="GND10" gate="1" x="215.9" y="-33.02" smashed="yes">
<attribute name="VALUE" x="213.36" y="-35.56" size="1.778" layer="96"/>
</instance>
<instance part="G2" gate="G$1" x="-73.66" y="-55.88" smashed="yes">
<attribute name="NAME" x="-73.66" y="-52.705" size="1.778" layer="95"/>
</instance>
<instance part="U$5" gate="G$1" x="-139.7" y="-45.72" smashed="yes">
<attribute name="NAME" x="-149.098" y="-19.558" size="1.27" layer="94"/>
</instance>
<instance part="DC4" gate="G$1" x="-91.44" y="-7.62" smashed="yes">
<attribute name="NAME" x="-101.6" y="-1.905" size="1.778" layer="95"/>
<attribute name="VALUE" x="-101.6" y="-17.78" size="1.778" layer="96"/>
</instance>
<instance part="U$7" gate="G$1" x="-78.74" y="-35.56" smashed="yes"/>
<instance part="Q9" gate="G$1" x="-124.46" y="5.08" smashed="yes">
<attribute name="NAME" x="-116.84" y="7.62" size="1.778" layer="95"/>
<attribute name="VALUE" x="-116.84" y="5.08" size="1.778" layer="96"/>
</instance>
<instance part="GND3" gate="1" x="-104.14" y="7.62" smashed="yes">
<attribute name="VALUE" x="-106.68" y="5.08" size="1.778" layer="96"/>
</instance>
<instance part="R10" gate="G$1" x="-132.08" y="-2.54" smashed="yes" rot="R90">
<attribute name="NAME" x="-134.62" y="-5.08" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="-128.27" y="-5.08" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="R11" gate="G$1" x="-132.08" y="7.62" smashed="yes" rot="R90">
<attribute name="NAME" x="-134.62" y="5.08" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="-128.27" y="5.08" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="D1" gate="1" x="-142.24" y="2.54" smashed="yes">
<attribute name="NAME" x="-139.7" y="3.0226" size="1.778" layer="95"/>
</instance>
<instance part="D2" gate="1" x="-152.4" y="-5.08" smashed="yes">
<attribute name="NAME" x="-149.86" y="-7.1374" size="1.778" layer="95"/>
</instance>
<instance part="D3" gate="1" x="-152.4" y="10.16" smashed="yes">
<attribute name="NAME" x="-149.86" y="10.6426" size="1.778" layer="95"/>
</instance>
<instance part="D4" gate="1" x="-147.32" y="2.54" smashed="yes" rot="R180">
<attribute name="NAME" x="-149.86" y="2.0574" size="1.778" layer="95" rot="R180"/>
</instance>
<instance part="U$2" gate="G$1" x="35.56" y="-45.72" smashed="yes"/>
<instance part="GND7" gate="1" x="17.78" y="-50.8" smashed="yes">
<attribute name="VALUE" x="15.24" y="-53.34" size="1.778" layer="96"/>
</instance>
<instance part="U$3" gate="G$1" x="35.56" y="27.94" smashed="yes"/>
<instance part="GND8" gate="1" x="17.78" y="22.86" smashed="yes">
<attribute name="VALUE" x="15.24" y="20.32" size="1.778" layer="96"/>
</instance>
<instance part="U$8" gate="G$1" x="35.56" y="-22.86" smashed="yes"/>
<instance part="GND11" gate="1" x="17.78" y="-27.94" smashed="yes">
<attribute name="VALUE" x="15.24" y="-30.48" size="1.778" layer="96"/>
</instance>
<instance part="U$9" gate="G$1" x="35.56" y="0" smashed="yes"/>
<instance part="GND12" gate="1" x="17.78" y="-5.08" smashed="yes">
<attribute name="VALUE" x="15.24" y="-7.62" size="1.778" layer="96"/>
</instance>
<instance part="R12" gate="G$1" x="129.54" y="-5.08" smashed="yes" rot="R90">
<attribute name="NAME" x="127" y="-7.62" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="133.35" y="-7.62" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="GND13" gate="1" x="137.16" y="-12.7" smashed="yes">
<attribute name="VALUE" x="134.62" y="-15.24" size="1.778" layer="96"/>
</instance>
<instance part="R13" gate="G$1" x="144.78" y="-5.08" smashed="yes" rot="R90">
<attribute name="NAME" x="142.24" y="-7.62" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="148.59" y="-7.62" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="P1" gate="G$1" x="175.26" y="-71.12" smashed="yes" rot="R180">
<attribute name="NAME" x="176.53" y="-79.375" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="176.53" y="-60.96" size="1.778" layer="95" rot="R180"/>
</instance>
<instance part="GND14" gate="1" x="203.2" y="-86.36" smashed="yes">
<attribute name="VALUE" x="200.66" y="-88.9" size="1.778" layer="96"/>
</instance>
<instance part="P2" gate="G$1" x="233.68" y="-71.12" smashed="yes">
<attribute name="NAME" x="232.41" y="-62.865" size="1.778" layer="95"/>
<attribute name="VALUE" x="232.41" y="-81.28" size="1.778" layer="95"/>
</instance>
<instance part="P3" gate="G$1" x="137.16" y="-71.12" smashed="yes">
<attribute name="NAME" x="135.89" y="-65.405" size="1.778" layer="95"/>
<attribute name="VALUE" x="135.89" y="-78.74" size="1.778" layer="95"/>
</instance>
<instance part="P4" gate="G$1" x="83.82" y="-71.12" smashed="yes" rot="R180">
<attribute name="NAME" x="85.09" y="-79.375" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="85.09" y="-63.5" size="1.778" layer="95" rot="R180"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="GND" class="0">
<segment>
<pinref part="GND4" gate="1" pin="GND"/>
<pinref part="DC1" gate="G$1" pin="-VIN"/>
<wire x1="-40.64" y1="-2.54" x2="-53.34" y2="-2.54" width="0.1524" layer="91"/>
<wire x1="-53.34" y1="-2.54" x2="-53.34" y2="5.08" width="0.1524" layer="91"/>
<wire x1="-40.64" y1="-2.54" x2="-27.94" y2="-2.54" width="0.1524" layer="91"/>
<junction x="-40.64" y="-2.54"/>
<pinref part="DC1" gate="G$1" pin="-VOUT"/>
<wire x1="-27.94" y1="-2.54" x2="-27.94" y2="5.08" width="0.1524" layer="91"/>
<pinref part="Q4" gate="G$1" pin="S"/>
<wire x1="-27.94" y1="-2.54" x2="2.54" y2="-2.54" width="0.1524" layer="91"/>
<junction x="-27.94" y="-2.54"/>
</segment>
<segment>
<pinref part="GND5" gate="1" pin="GND"/>
<pinref part="DC2" gate="G$1" pin="-VIN"/>
<wire x1="-40.64" y1="-25.4" x2="-53.34" y2="-25.4" width="0.1524" layer="91"/>
<wire x1="-53.34" y1="-25.4" x2="-53.34" y2="-17.78" width="0.1524" layer="91"/>
<wire x1="-40.64" y1="-25.4" x2="-27.94" y2="-25.4" width="0.1524" layer="91"/>
<junction x="-40.64" y="-25.4"/>
<pinref part="DC2" gate="G$1" pin="-VOUT"/>
<wire x1="-27.94" y1="-25.4" x2="-27.94" y2="-17.78" width="0.1524" layer="91"/>
<pinref part="Q6" gate="G$1" pin="S"/>
<wire x1="-27.94" y1="-25.4" x2="2.54" y2="-25.4" width="0.1524" layer="91"/>
<junction x="-27.94" y="-25.4"/>
</segment>
<segment>
<pinref part="GND6" gate="1" pin="GND"/>
<pinref part="DC3" gate="G$1" pin="-VIN"/>
<wire x1="-40.64" y1="-48.26" x2="-53.34" y2="-48.26" width="0.1524" layer="91"/>
<wire x1="-53.34" y1="-48.26" x2="-53.34" y2="-40.64" width="0.1524" layer="91"/>
<wire x1="-40.64" y1="-48.26" x2="-27.94" y2="-48.26" width="0.1524" layer="91"/>
<junction x="-40.64" y="-48.26"/>
<pinref part="DC3" gate="G$1" pin="-VOUT"/>
<wire x1="-27.94" y1="-48.26" x2="-27.94" y2="-40.64" width="0.1524" layer="91"/>
<pinref part="Q8" gate="G$1" pin="S"/>
<wire x1="-27.94" y1="-48.26" x2="2.54" y2="-48.26" width="0.1524" layer="91"/>
<junction x="-27.94" y="-48.26"/>
</segment>
<segment>
<pinref part="Q2" gate="G$1" pin="S"/>
<pinref part="GND1" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="GND"/>
<pinref part="GND2" gate="1" pin="GND"/>
<wire x1="119.38" y1="40.64" x2="132.08" y2="40.64" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND9" gate="1" pin="GND"/>
<wire x1="144.78" y1="-30.48" x2="154.94" y2="-30.48" width="0.1524" layer="91"/>
<wire x1="154.94" y1="-30.48" x2="157.48" y2="-33.02" width="0.1524" layer="91"/>
<pinref part="U$4" gate="G$1" pin="VSS"/>
</segment>
<segment>
<pinref part="R9" gate="G$1" pin="2"/>
<pinref part="GND10" gate="1" pin="GND"/>
<wire x1="208.28" y1="-30.48" x2="215.9" y2="-30.48" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="Q9" gate="G$1" pin="D"/>
<wire x1="-121.92" y1="10.16" x2="-121.92" y2="12.7" width="0.1524" layer="91"/>
<wire x1="-121.92" y1="12.7" x2="-119.38" y2="15.24" width="0.1524" layer="91"/>
<wire x1="-119.38" y1="15.24" x2="-106.68" y2="15.24" width="0.1524" layer="91"/>
<pinref part="GND3" gate="1" pin="GND"/>
<wire x1="-106.68" y1="15.24" x2="-104.14" y2="12.7" width="0.1524" layer="91"/>
<wire x1="-104.14" y1="12.7" x2="-104.14" y2="10.16" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND7" gate="1" pin="GND"/>
<pinref part="U$2" gate="G$1" pin="GND"/>
<wire x1="17.78" y1="-48.26" x2="20.32" y2="-45.72" width="0.1524" layer="91"/>
<wire x1="20.32" y1="-45.72" x2="22.86" y2="-45.72" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND8" gate="1" pin="GND"/>
<pinref part="U$3" gate="G$1" pin="GND"/>
<wire x1="17.78" y1="25.4" x2="20.32" y2="27.94" width="0.1524" layer="91"/>
<wire x1="20.32" y1="27.94" x2="22.86" y2="27.94" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND11" gate="1" pin="GND"/>
<pinref part="U$8" gate="G$1" pin="GND"/>
<wire x1="17.78" y1="-25.4" x2="20.32" y2="-22.86" width="0.1524" layer="91"/>
<wire x1="20.32" y1="-22.86" x2="22.86" y2="-22.86" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND12" gate="1" pin="GND"/>
<pinref part="U$9" gate="G$1" pin="GND"/>
<wire x1="17.78" y1="-2.54" x2="20.32" y2="0" width="0.1524" layer="91"/>
<wire x1="20.32" y1="0" x2="22.86" y2="0" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="R12" gate="G$1" pin="1"/>
<pinref part="GND13" gate="1" pin="GND"/>
<wire x1="129.54" y1="-10.16" x2="137.16" y2="-10.16" width="0.1524" layer="91"/>
<wire x1="137.16" y1="-10.16" x2="144.78" y2="-10.16" width="0.1524" layer="91"/>
<junction x="137.16" y="-10.16"/>
<pinref part="R13" gate="G$1" pin="1"/>
</segment>
<segment>
<pinref part="P1" gate="G$1" pin="1"/>
<wire x1="180.34" y1="-76.2" x2="203.2" y2="-76.2" width="0.1524" layer="91"/>
<pinref part="GND14" gate="1" pin="GND"/>
<wire x1="203.2" y1="-76.2" x2="203.2" y2="-83.82" width="0.1524" layer="91"/>
</segment>
</net>
<net name="KEY_PLUS" class="0">
<segment>
<pinref part="DC2" gate="G$1" pin="+VIN"/>
<pinref part="DC3" gate="G$1" pin="+VIN"/>
<wire x1="-60.96" y1="-12.7" x2="-53.34" y2="-12.7" width="0.1524" layer="91"/>
<wire x1="-53.34" y1="-35.56" x2="-60.96" y2="-35.56" width="0.1524" layer="91"/>
<wire x1="-60.96" y1="-35.56" x2="-60.96" y2="-12.7" width="0.1524" layer="91"/>
<junction x="-60.96" y="-12.7"/>
<pinref part="DC1" gate="G$1" pin="+VIN"/>
<wire x1="-53.34" y1="10.16" x2="-60.96" y2="10.16" width="0.1524" layer="91"/>
<wire x1="-60.96" y1="10.16" x2="-60.96" y2="-12.7" width="0.1524" layer="91"/>
<pinref part="Q1" gate="G$1" pin="S"/>
<wire x1="10.16" y1="43.18" x2="10.16" y2="45.72" width="0.1524" layer="91"/>
<pinref part="R1" gate="G$1" pin="2"/>
<wire x1="10.16" y1="45.72" x2="2.54" y2="45.72" width="0.1524" layer="91"/>
<wire x1="-60.96" y1="10.16" x2="-60.96" y2="45.72" width="0.1524" layer="91"/>
<wire x1="-60.96" y1="45.72" x2="2.54" y2="45.72" width="0.1524" layer="91"/>
<junction x="-60.96" y="10.16"/>
<junction x="2.54" y="45.72"/>
<pinref part="U$7" gate="G$1" pin="P+"/>
<wire x1="-73.66" y1="-20.32" x2="-73.66" y2="-12.7" width="0.1524" layer="91"/>
<wire x1="-73.66" y1="-12.7" x2="-60.96" y2="-12.7" width="0.1524" layer="91"/>
<pinref part="DC4" gate="G$1" pin="+VOUT"/>
<wire x1="-78.74" y1="-5.08" x2="-73.66" y2="-5.08" width="0.1524" layer="91"/>
<wire x1="-73.66" y1="-5.08" x2="-73.66" y2="-12.7" width="0.1524" layer="91"/>
<junction x="-73.66" y="-12.7"/>
<wire x1="-76.2" y1="20.32" x2="-73.66" y2="17.78" width="0.1524" layer="91"/>
<wire x1="-73.66" y1="17.78" x2="-73.66" y2="-5.08" width="0.1524" layer="91"/>
<junction x="-73.66" y="-5.08"/>
<wire x1="-96.52" y1="20.32" x2="-76.2" y2="20.32" width="0.1524" layer="91"/>
<label x="-96.52" y="20.32" size="1.778" layer="95"/>
</segment>
</net>
<net name="5V_CONTINUOUS" class="0">
<segment>
<pinref part="DC1" gate="G$1" pin="+VOUT"/>
<wire x1="-27.94" y1="10.16" x2="-22.86" y2="10.16" width="0.1524" layer="91"/>
<wire x1="-22.86" y1="10.16" x2="-22.86" y2="17.78" width="0.1524" layer="91"/>
<pinref part="R4" gate="G$1" pin="2"/>
<wire x1="-5.08" y1="10.16" x2="-22.86" y2="10.16" width="0.1524" layer="91"/>
<junction x="-22.86" y="10.16"/>
<pinref part="Q3" gate="G$1" pin="S"/>
<wire x1="10.16" y1="15.24" x2="10.16" y2="17.78" width="0.1524" layer="91"/>
<pinref part="R3" gate="G$1" pin="2"/>
<wire x1="10.16" y1="17.78" x2="2.54" y2="17.78" width="0.1524" layer="91"/>
<junction x="2.54" y="17.78"/>
<wire x1="2.54" y1="17.78" x2="-22.86" y2="17.78" width="0.1524" layer="91"/>
<wire x1="-22.86" y1="17.78" x2="-33.02" y2="17.78" width="0.1524" layer="91"/>
<junction x="-22.86" y="17.78"/>
<pinref part="R2" gate="G$1" pin="2"/>
<wire x1="-5.08" y1="38.1" x2="-33.02" y2="38.1" width="0.1524" layer="91"/>
<label x="-40.64" y="38.1" size="1.778" layer="95"/>
<wire x1="-33.02" y1="17.78" x2="-33.02" y2="38.1" width="0.1524" layer="91"/>
<wire x1="-33.02" y1="38.1" x2="-40.64" y2="38.1" width="0.1524" layer="91"/>
<junction x="-33.02" y="38.1"/>
<wire x1="10.16" y1="17.78" x2="20.32" y2="17.78" width="0.1524" layer="91"/>
<wire x1="20.32" y1="17.78" x2="22.86" y2="20.32" width="0.1524" layer="91"/>
<junction x="10.16" y="17.78"/>
<pinref part="U$3" gate="G$1" pin="VCC"/>
<wire x1="22.86" y1="20.32" x2="22.86" y2="22.86" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="R6" gate="G$1" pin="2"/>
<wire x1="-5.08" y1="-12.7" x2="-25.4" y2="-12.7" width="0.1524" layer="91"/>
<label x="-25.4" y="-12.7" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="R8" gate="G$1" pin="2"/>
<wire x1="-5.08" y1="-35.56" x2="-25.4" y2="-35.56" width="0.1524" layer="91"/>
<label x="-25.4" y="-35.56" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="5V"/>
<wire x1="119.38" y1="30.48" x2="121.92" y2="30.48" width="0.1524" layer="91"/>
<label x="121.92" y="30.48" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$4" gate="G$1" pin="VDD"/>
<wire x1="157.48" y1="-35.56" x2="154.94" y2="-38.1" width="0.1524" layer="91"/>
<wire x1="154.94" y1="-38.1" x2="132.08" y2="-38.1" width="0.1524" layer="91"/>
<label x="132.08" y="-38.1" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="D4" gate="1" pin="C"/>
<wire x1="-149.86" y1="2.54" x2="-172.72" y2="2.54" width="0.1524" layer="91"/>
<label x="-172.72" y="2.54" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$2" gate="G$1" pin="VCC"/>
<wire x1="22.86" y1="-50.8" x2="22.86" y2="-53.34" width="0.1524" layer="91"/>
<label x="25.4" y="-55.88" size="1.778" layer="95"/>
<wire x1="25.4" y1="-55.88" x2="45.72" y2="-55.88" width="0.1524" layer="91"/>
<wire x1="22.86" y1="-53.34" x2="25.4" y2="-55.88" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="U$8" gate="G$1" pin="VCC"/>
<wire x1="22.86" y1="-27.94" x2="22.86" y2="-30.48" width="0.1524" layer="91"/>
<label x="25.4" y="-33.02" size="1.778" layer="95"/>
<wire x1="25.4" y1="-33.02" x2="45.72" y2="-33.02" width="0.1524" layer="91"/>
<wire x1="22.86" y1="-30.48" x2="25.4" y2="-33.02" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="U$9" gate="G$1" pin="VCC"/>
<wire x1="22.86" y1="-5.08" x2="22.86" y2="-7.62" width="0.1524" layer="91"/>
<label x="25.4" y="-10.16" size="1.778" layer="95"/>
<wire x1="25.4" y1="-10.16" x2="45.72" y2="-10.16" width="0.1524" layer="91"/>
<wire x1="22.86" y1="-7.62" x2="25.4" y2="-10.16" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$1" class="0">
<segment>
<pinref part="Q1" gate="G$1" pin="G"/>
<pinref part="R1" gate="G$1" pin="1"/>
<pinref part="Q2" gate="G$1" pin="D"/>
<junction x="2.54" y="35.56"/>
</segment>
</net>
<net name="PCTRL_HEATER" class="0">
<segment>
<pinref part="R2" gate="G$1" pin="1"/>
<pinref part="Q2" gate="G$1" pin="G"/>
<wire x1="-5.08" y1="27.94" x2="-2.54" y2="27.94" width="0.1524" layer="91"/>
<wire x1="-5.08" y1="27.94" x2="-25.4" y2="27.94" width="0.1524" layer="91"/>
<junction x="-5.08" y="27.94"/>
<label x="-25.4" y="27.94" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="PA3"/>
<wire x1="119.38" y1="10.16" x2="121.92" y2="10.16" width="0.1524" layer="91"/>
<label x="121.92" y="10.16" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="Q3" gate="G$1" pin="G"/>
<pinref part="R3" gate="G$1" pin="1"/>
<pinref part="Q4" gate="G$1" pin="D"/>
<junction x="2.54" y="7.62"/>
</segment>
</net>
<net name="PCTRL_CCU" class="0">
<segment>
<pinref part="R4" gate="G$1" pin="1"/>
<pinref part="Q4" gate="G$1" pin="G"/>
<wire x1="-5.08" y1="0" x2="-2.54" y2="0" width="0.1524" layer="91"/>
<wire x1="-5.08" y1="0" x2="-25.4" y2="0" width="0.1524" layer="91"/>
<junction x="-5.08" y="0"/>
<label x="-25.4" y="0" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="PA0"/>
<wire x1="119.38" y1="25.4" x2="121.92" y2="25.4" width="0.1524" layer="91"/>
<label x="121.92" y="25.4" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="Q5" gate="G$1" pin="G"/>
<pinref part="R5" gate="G$1" pin="1"/>
<pinref part="Q6" gate="G$1" pin="D"/>
<junction x="2.54" y="-15.24"/>
</segment>
</net>
<net name="PCTRL_SCU" class="0">
<segment>
<pinref part="R6" gate="G$1" pin="1"/>
<pinref part="Q6" gate="G$1" pin="G"/>
<wire x1="-5.08" y1="-22.86" x2="-2.54" y2="-22.86" width="0.1524" layer="91"/>
<wire x1="-5.08" y1="-22.86" x2="-25.4" y2="-22.86" width="0.1524" layer="91"/>
<junction x="-5.08" y="-22.86"/>
<label x="-25.4" y="-22.86" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="PA1"/>
<wire x1="119.38" y1="20.32" x2="121.92" y2="20.32" width="0.1524" layer="91"/>
<label x="121.92" y="20.32" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="DC2" gate="G$1" pin="+VOUT"/>
<wire x1="-27.94" y1="-12.7" x2="-27.94" y2="-5.08" width="0.1524" layer="91"/>
<pinref part="R5" gate="G$1" pin="2"/>
<wire x1="-27.94" y1="-5.08" x2="2.54" y2="-5.08" width="0.1524" layer="91"/>
<pinref part="Q5" gate="G$1" pin="S"/>
<wire x1="2.54" y1="-5.08" x2="10.16" y2="-5.08" width="0.1524" layer="91"/>
<wire x1="10.16" y1="-5.08" x2="10.16" y2="-7.62" width="0.1524" layer="91"/>
<junction x="2.54" y="-5.08"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="Q7" gate="G$1" pin="G"/>
<pinref part="R7" gate="G$1" pin="1"/>
<pinref part="Q8" gate="G$1" pin="D"/>
<junction x="2.54" y="-38.1"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="R7" gate="G$1" pin="2"/>
<wire x1="-27.94" y1="-27.94" x2="2.54" y2="-27.94" width="0.1524" layer="91"/>
<pinref part="Q7" gate="G$1" pin="S"/>
<wire x1="2.54" y1="-27.94" x2="10.16" y2="-27.94" width="0.1524" layer="91"/>
<wire x1="10.16" y1="-27.94" x2="10.16" y2="-30.48" width="0.1524" layer="91"/>
<junction x="2.54" y="-27.94"/>
<pinref part="DC3" gate="G$1" pin="+VOUT"/>
<wire x1="-27.94" y1="-35.56" x2="-27.94" y2="-27.94" width="0.1524" layer="91"/>
</segment>
</net>
<net name="PCTRL_ICU" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="PA2"/>
<wire x1="119.38" y1="15.24" x2="121.92" y2="15.24" width="0.1524" layer="91"/>
<label x="121.92" y="15.24" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="R8" gate="G$1" pin="1"/>
<pinref part="Q8" gate="G$1" pin="G"/>
<wire x1="-5.08" y1="-45.72" x2="-2.54" y2="-45.72" width="0.1524" layer="91"/>
<wire x1="-5.08" y1="-45.72" x2="-25.4" y2="-45.72" width="0.1524" layer="91"/>
<junction x="-5.08" y="-45.72"/>
<label x="-25.4" y="-45.72" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$9" class="0">
<segment>
<pinref part="Q3" gate="G$1" pin="D"/>
<wire x1="10.16" y1="5.08" x2="22.86" y2="5.08" width="0.1524" layer="91"/>
<pinref part="U$9" gate="G$1" pin="VIN+"/>
</segment>
</net>
<net name="N$10" class="0">
<segment>
<pinref part="Q5" gate="G$1" pin="D"/>
<wire x1="10.16" y1="-17.78" x2="22.86" y2="-17.78" width="0.1524" layer="91"/>
<pinref part="U$8" gate="G$1" pin="VIN+"/>
</segment>
</net>
<net name="N$11" class="0">
<segment>
<pinref part="Q7" gate="G$1" pin="D"/>
<wire x1="22.86" y1="-40.64" x2="10.16" y2="-40.64" width="0.1524" layer="91"/>
<pinref part="U$2" gate="G$1" pin="VIN+"/>
</segment>
</net>
<net name="N$14" class="0">
<segment>
<pinref part="U$4" gate="G$1" pin="TXD"/>
<wire x1="157.48" y1="-30.48" x2="154.94" y2="-27.94" width="0.1524" layer="91"/>
<wire x1="154.94" y1="-27.94" x2="139.7" y2="-27.94" width="0.1524" layer="91"/>
<wire x1="139.7" y1="-27.94" x2="137.16" y2="-30.48" width="0.1524" layer="91"/>
<wire x1="137.16" y1="-30.48" x2="124.46" y2="-30.48" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="PA12"/>
<wire x1="119.38" y1="-35.56" x2="124.46" y2="-30.48" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$15" class="0">
<segment>
<pinref part="U$4" gate="G$1" pin="RXD"/>
<wire x1="157.48" y1="-38.1" x2="154.94" y2="-40.64" width="0.1524" layer="91"/>
<wire x1="154.94" y1="-40.64" x2="132.08" y2="-40.64" width="0.1524" layer="91"/>
<wire x1="132.08" y1="-40.64" x2="127" y2="-35.56" width="0.1524" layer="91"/>
<wire x1="127" y1="-35.56" x2="124.46" y2="-35.56" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="PA11"/>
<wire x1="124.46" y1="-35.56" x2="119.38" y2="-30.48" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$16" class="0">
<segment>
<pinref part="U$4" gate="G$1" pin="RS"/>
<pinref part="R9" gate="G$1" pin="1"/>
<wire x1="198.12" y1="-30.48" x2="190.5" y2="-30.48" width="0.1524" layer="91"/>
</segment>
</net>
<net name="CANH" class="0">
<segment>
<pinref part="P1" gate="G$1" pin="3"/>
<pinref part="P2" gate="G$1" pin="3"/>
<wire x1="180.34" y1="-71.12" x2="205.74" y2="-71.12" width="0.1524" layer="91"/>
<wire x1="205.74" y1="-71.12" x2="228.6" y2="-71.12" width="0.1524" layer="91"/>
<wire x1="205.74" y1="-35.56" x2="205.74" y2="-71.12" width="0.1524" layer="91"/>
<junction x="205.74" y="-71.12"/>
<wire x1="205.74" y1="-35.56" x2="203.2" y2="-33.02" width="0.1524" layer="91"/>
<pinref part="U$4" gate="G$1" pin="CANH"/>
<wire x1="203.2" y1="-33.02" x2="190.5" y2="-33.02" width="0.1524" layer="91"/>
</segment>
</net>
<net name="CANL" class="0">
<segment>
<pinref part="U$4" gate="G$1" pin="CANL"/>
<wire x1="190.5" y1="-35.56" x2="200.66" y2="-35.56" width="0.1524" layer="91"/>
<pinref part="P1" gate="G$1" pin="2"/>
<pinref part="P2" gate="G$1" pin="4"/>
<wire x1="180.34" y1="-73.66" x2="203.2" y2="-73.66" width="0.1524" layer="91"/>
<wire x1="203.2" y1="-73.66" x2="228.6" y2="-73.66" width="0.1524" layer="91"/>
<wire x1="200.66" y1="-35.56" x2="203.2" y2="-38.1" width="0.1524" layer="91"/>
<wire x1="203.2" y1="-38.1" x2="203.2" y2="-73.66" width="0.1524" layer="91"/>
<junction x="203.2" y="-73.66"/>
</segment>
</net>
<net name="N$17" class="0">
<segment>
<pinref part="G2" gate="G$1" pin="-"/>
<pinref part="G1" gate="G$1" pin="+"/>
<pinref part="U$7" gate="G$1" pin="BALANCE"/>
<wire x1="-78.74" y1="-55.88" x2="-78.74" y2="-45.72" width="0.1524" layer="91"/>
<junction x="-78.74" y="-55.88"/>
</segment>
</net>
<net name="USB_SBU2" class="0">
<segment>
<pinref part="U$5" gate="G$1" pin="B8"/>
<wire x1="-127" y1="-33.02" x2="-114.3" y2="-33.02" width="0.1524" layer="91"/>
<label x="-127" y="-33.02" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="D2" gate="1" pin="A"/>
<wire x1="-154.94" y1="-5.08" x2="-172.72" y2="-5.08" width="0.1524" layer="91"/>
<label x="-172.72" y="-5.08" size="1.778" layer="95"/>
</segment>
</net>
<net name="USB_DMINUS" class="0">
<segment>
<pinref part="U$5" gate="G$1" pin="B7"/>
<wire x1="-127" y1="-35.56" x2="-114.3" y2="-35.56" width="0.1524" layer="91"/>
<label x="-127" y="-35.56" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$5" gate="G$1" pin="A7"/>
<wire x1="-154.94" y1="-38.1" x2="-167.64" y2="-38.1" width="0.1524" layer="91"/>
<label x="-167.64" y="-38.1" size="1.778" layer="95"/>
</segment>
</net>
<net name="USB_DPLUS" class="0">
<segment>
<pinref part="U$5" gate="G$1" pin="B6"/>
<wire x1="-127" y1="-38.1" x2="-114.3" y2="-38.1" width="0.1524" layer="91"/>
<label x="-127" y="-38.1" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$5" gate="G$1" pin="A6"/>
<wire x1="-154.94" y1="-35.56" x2="-167.64" y2="-35.56" width="0.1524" layer="91"/>
<label x="-167.64" y="-35.56" size="1.778" layer="95"/>
</segment>
</net>
<net name="SWDIO_2" class="0">
<segment>
<pinref part="U$5" gate="G$1" pin="B2"/>
<wire x1="-127" y1="-48.26" x2="-114.3" y2="-48.26" width="0.1524" layer="91"/>
<label x="-124.46" y="-48.26" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="P4" gate="G$1" pin="4"/>
<wire x1="88.9" y1="-68.58" x2="101.6" y2="-68.58" width="0.1524" layer="91"/>
<label x="91.44" y="-68.58" size="1.778" layer="95"/>
</segment>
</net>
<net name="SWCLK_2" class="0">
<segment>
<pinref part="U$5" gate="G$1" pin="B3"/>
<wire x1="-127" y1="-45.72" x2="-114.3" y2="-45.72" width="0.1524" layer="91"/>
<label x="-124.46" y="-45.72" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="P4" gate="G$1" pin="3"/>
<wire x1="88.9" y1="-71.12" x2="101.6" y2="-71.12" width="0.1524" layer="91"/>
<label x="91.44" y="-71.12" size="1.778" layer="95"/>
</segment>
</net>
<net name="SWCLK_3" class="0">
<segment>
<pinref part="U$5" gate="G$1" pin="B10"/>
<wire x1="-114.3" y1="-27.94" x2="-127" y2="-27.94" width="0.1524" layer="91"/>
<label x="-124.46" y="-27.94" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="P4" gate="G$1" pin="1"/>
<wire x1="88.9" y1="-76.2" x2="101.6" y2="-76.2" width="0.1524" layer="91"/>
<label x="91.44" y="-76.2" size="1.778" layer="95"/>
</segment>
</net>
<net name="SWDIO_3" class="0">
<segment>
<pinref part="U$5" gate="G$1" pin="B11"/>
<wire x1="-127" y1="-25.4" x2="-114.3" y2="-25.4" width="0.1524" layer="91"/>
<label x="-124.46" y="-25.4" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="P4" gate="G$1" pin="2"/>
<wire x1="88.9" y1="-73.66" x2="101.6" y2="-73.66" width="0.1524" layer="91"/>
<label x="91.44" y="-73.66" size="1.778" layer="95"/>
</segment>
</net>
<net name="USB_CC1" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="PA4"/>
<label x="147.32" y="5.08" size="1.778" layer="95"/>
<wire x1="119.38" y1="5.08" x2="144.78" y2="5.08" width="0.1524" layer="91"/>
<pinref part="R13" gate="G$1" pin="2"/>
<wire x1="144.78" y1="5.08" x2="144.78" y2="0" width="0.1524" layer="91"/>
<wire x1="144.78" y1="5.08" x2="152.4" y2="5.08" width="0.1524" layer="91"/>
<junction x="144.78" y="5.08"/>
</segment>
<segment>
<pinref part="U$5" gate="G$1" pin="A5"/>
<wire x1="-154.94" y1="-33.02" x2="-167.64" y2="-33.02" width="0.1524" layer="91"/>
<label x="-167.64" y="-33.02" size="1.778" layer="95"/>
</segment>
</net>
<net name="USB_CC2" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="PA5"/>
<label x="132.08" y="0" size="1.778" layer="95"/>
<wire x1="119.38" y1="0" x2="129.54" y2="0" width="0.1524" layer="91"/>
<pinref part="R12" gate="G$1" pin="2"/>
<wire x1="129.54" y1="0" x2="137.16" y2="0" width="0.1524" layer="91"/>
<junction x="129.54" y="0"/>
</segment>
<segment>
<pinref part="U$5" gate="G$1" pin="B5"/>
<wire x1="-127" y1="-40.64" x2="-114.3" y2="-40.64" width="0.1524" layer="91"/>
<label x="-127" y="-40.64" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$19" class="0">
<segment>
<pinref part="U$5" gate="G$1" pin="B9"/>
<wire x1="-127" y1="-30.48" x2="-109.22" y2="-30.48" width="0.1524" layer="91"/>
<wire x1="-109.22" y1="-30.48" x2="-109.22" y2="-43.18" width="0.1524" layer="91"/>
<pinref part="U$5" gate="G$1" pin="B4"/>
<wire x1="-109.22" y1="-43.18" x2="-127" y2="-43.18" width="0.1524" layer="91"/>
<pinref part="U$5" gate="G$1" pin="A9"/>
<wire x1="-154.94" y1="-43.18" x2="-172.72" y2="-43.18" width="0.1524" layer="91"/>
<pinref part="U$5" gate="G$1" pin="A4"/>
<wire x1="-172.72" y1="-43.18" x2="-172.72" y2="-30.48" width="0.1524" layer="91"/>
<wire x1="-172.72" y1="-30.48" x2="-154.94" y2="-30.48" width="0.1524" layer="91"/>
<wire x1="-172.72" y1="-30.48" x2="-172.72" y2="-12.7" width="0.1524" layer="91"/>
<wire x1="-172.72" y1="-12.7" x2="-109.22" y2="-12.7" width="0.1524" layer="91"/>
<junction x="-172.72" y="-30.48"/>
<wire x1="-109.22" y1="-30.48" x2="-109.22" y2="-12.7" width="0.1524" layer="91"/>
<junction x="-109.22" y="-30.48"/>
<wire x1="-109.22" y1="-12.7" x2="-109.22" y2="-7.62" width="0.1524" layer="91"/>
<wire x1="-109.22" y1="-7.62" x2="-106.68" y2="-5.08" width="0.1524" layer="91"/>
<junction x="-109.22" y="-12.7"/>
<pinref part="DC4" gate="G$1" pin="+VIN"/>
<wire x1="-106.68" y1="-5.08" x2="-104.14" y2="-5.08" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$20" class="0">
<segment>
<pinref part="U$7" gate="G$1" pin="B-"/>
<wire x1="-86.36" y1="-45.72" x2="-88.9" y2="-50.8" width="0.1524" layer="91"/>
<pinref part="G1" gate="G$1" pin="-"/>
<wire x1="-88.9" y1="-50.8" x2="-88.9" y2="-55.88" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$21" class="0">
<segment>
<pinref part="U$7" gate="G$1" pin="B+"/>
<wire x1="-71.12" y1="-45.72" x2="-68.58" y2="-50.8" width="0.1524" layer="91"/>
<pinref part="G2" gate="G$1" pin="+"/>
<wire x1="-68.58" y1="-50.8" x2="-68.58" y2="-55.88" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$24" class="0">
<segment>
<pinref part="U$5" gate="G$1" pin="B1"/>
<pinref part="U$5" gate="G$1" pin="A12"/>
<wire x1="-154.94" y1="-50.8" x2="-154.94" y2="-55.88" width="0.1524" layer="91"/>
<wire x1="-154.94" y1="-55.88" x2="-127" y2="-55.88" width="0.1524" layer="91"/>
<wire x1="-127" y1="-55.88" x2="-127" y2="-50.8" width="0.1524" layer="91"/>
<pinref part="DC4" gate="G$1" pin="-VIN"/>
<wire x1="-104.14" y1="-17.78" x2="-104.14" y2="-10.16" width="0.1524" layer="91"/>
<wire x1="-104.14" y1="-17.78" x2="-83.82" y2="-17.78" width="0.1524" layer="91"/>
<pinref part="DC4" gate="G$1" pin="-VOUT"/>
<wire x1="-83.82" y1="-17.78" x2="-78.74" y2="-17.78" width="0.1524" layer="91"/>
<wire x1="-78.74" y1="-17.78" x2="-78.74" y2="-10.16" width="0.1524" layer="91"/>
<pinref part="U$7" gate="G$1" pin="P-"/>
<wire x1="-83.82" y1="-20.32" x2="-83.82" y2="-17.78" width="0.1524" layer="91"/>
<junction x="-83.82" y="-17.78"/>
<junction x="-104.14" y="-17.78"/>
<wire x1="-127" y1="-55.88" x2="-104.14" y2="-55.88" width="0.1524" layer="91"/>
<wire x1="-104.14" y1="-55.88" x2="-104.14" y2="-17.78" width="0.1524" layer="91"/>
<junction x="-127" y="-55.88"/>
<wire x1="-104.14" y1="-17.78" x2="-116.84" y2="-17.78" width="0.1524" layer="91"/>
<wire x1="-116.84" y1="-17.78" x2="-119.38" y2="-15.24" width="0.1524" layer="91"/>
<pinref part="U$5" gate="G$1" pin="A1"/>
<wire x1="-154.94" y1="-22.86" x2="-154.94" y2="-15.24" width="0.1524" layer="91"/>
<wire x1="-154.94" y1="-15.24" x2="-127" y2="-15.24" width="0.1524" layer="91"/>
<wire x1="-127" y1="-15.24" x2="-121.92" y2="-15.24" width="0.1524" layer="91"/>
<wire x1="-119.38" y1="-15.24" x2="-121.92" y2="-15.24" width="0.1524" layer="91"/>
<junction x="-121.92" y="-15.24"/>
<pinref part="Q9" gate="G$1" pin="S"/>
<wire x1="-121.92" y1="-15.24" x2="-121.92" y2="-7.62" width="0.1524" layer="91"/>
<pinref part="R10" gate="G$1" pin="1"/>
<wire x1="-121.92" y1="-7.62" x2="-121.92" y2="0" width="0.1524" layer="91"/>
<wire x1="-132.08" y1="-7.62" x2="-121.92" y2="-7.62" width="0.1524" layer="91"/>
<junction x="-121.92" y="-7.62"/>
<pinref part="U$5" gate="G$1" pin="B12"/>
<wire x1="-127" y1="-22.86" x2="-127" y2="-15.24" width="0.1524" layer="91"/>
<junction x="-127" y="-15.24"/>
</segment>
</net>
<net name="USB_SBU1" class="0">
<segment>
<pinref part="U$5" gate="G$1" pin="A8"/>
<wire x1="-154.94" y1="-40.64" x2="-167.64" y2="-40.64" width="0.1524" layer="91"/>
<label x="-167.64" y="-40.64" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="D3" gate="1" pin="A"/>
<wire x1="-154.94" y1="10.16" x2="-172.72" y2="10.16" width="0.1524" layer="91"/>
<label x="-172.72" y="7.62" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$18" class="0">
<segment>
<pinref part="R10" gate="G$1" pin="2"/>
<pinref part="Q9" gate="G$1" pin="G"/>
<wire x1="-132.08" y1="2.54" x2="-127" y2="2.54" width="0.1524" layer="91"/>
<pinref part="R11" gate="G$1" pin="1"/>
<junction x="-132.08" y="2.54"/>
<pinref part="D1" gate="1" pin="C"/>
<wire x1="-139.7" y1="2.54" x2="-132.08" y2="2.54" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="D2" gate="1" pin="C"/>
<pinref part="D1" gate="1" pin="A"/>
<wire x1="-149.86" y1="-5.08" x2="-144.78" y2="-2.54" width="0.1524" layer="91"/>
<wire x1="-144.78" y1="-2.54" x2="-144.78" y2="2.54" width="0.1524" layer="91"/>
<pinref part="D3" gate="1" pin="C"/>
<wire x1="-149.86" y1="10.16" x2="-144.78" y2="7.62" width="0.1524" layer="91"/>
<wire x1="-144.78" y1="7.62" x2="-144.78" y2="2.54" width="0.1524" layer="91"/>
<junction x="-144.78" y="2.54"/>
<pinref part="D4" gate="1" pin="A"/>
</segment>
</net>
<net name="KEY_MINUS" class="0">
<segment>
<pinref part="R11" gate="G$1" pin="2"/>
<wire x1="-132.08" y1="12.7" x2="-132.08" y2="17.78" width="0.1524" layer="91"/>
<wire x1="-132.08" y1="17.78" x2="-129.54" y2="20.32" width="0.1524" layer="91"/>
<wire x1="-129.54" y1="20.32" x2="-106.68" y2="20.32" width="0.1524" layer="91"/>
<wire x1="-106.68" y1="20.32" x2="-101.6" y2="25.4" width="0.1524" layer="91"/>
<wire x1="-101.6" y1="25.4" x2="-83.82" y2="25.4" width="0.1524" layer="91"/>
<label x="-96.52" y="25.4" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="VIN+"/>
<pinref part="Q1" gate="G$1" pin="D"/>
<wire x1="22.86" y1="33.02" x2="10.16" y2="33.02" width="0.1524" layer="91"/>
</segment>
</net>
<net name="5V_CCU" class="0">
<segment>
<pinref part="U$9" gate="G$1" pin="VIN-"/>
<wire x1="48.26" y1="5.08" x2="66.04" y2="5.08" width="0.1524" layer="91"/>
<label x="55.88" y="5.08" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="P1" gate="G$1" pin="4"/>
<wire x1="180.34" y1="-68.58" x2="195.58" y2="-68.58" width="0.1524" layer="91"/>
<label x="185.42" y="-68.58" size="1.778" layer="95"/>
</segment>
</net>
<net name="5V_SCU" class="0">
<segment>
<pinref part="U$8" gate="G$1" pin="VIN-"/>
<wire x1="48.26" y1="-17.78" x2="66.04" y2="-17.78" width="0.1524" layer="91"/>
<label x="55.88" y="-17.78" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="P1" gate="G$1" pin="5"/>
<wire x1="180.34" y1="-66.04" x2="195.58" y2="-66.04" width="0.1524" layer="91"/>
<label x="185.42" y="-66.04" size="1.778" layer="95"/>
</segment>
</net>
<net name="5V_ICU" class="0">
<segment>
<pinref part="U$2" gate="G$1" pin="VIN-"/>
<wire x1="48.26" y1="-40.64" x2="66.04" y2="-40.64" width="0.1524" layer="91"/>
<label x="55.88" y="-40.64" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="P2" gate="G$1" pin="1"/>
<wire x1="228.6" y1="-66.04" x2="215.9" y2="-66.04" width="0.1524" layer="91"/>
<label x="215.9" y="-66.04" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$13" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="PB10"/>
<pinref part="U$3" gate="G$1" pin="SCL"/>
<wire x1="73.66" y1="-43.18" x2="73.66" y2="-25.4" width="0.1524" layer="91"/>
<wire x1="73.66" y1="-25.4" x2="73.66" y2="-12.7" width="0.1524" layer="91"/>
<wire x1="73.66" y1="-12.7" x2="73.66" y2="-2.54" width="0.1524" layer="91"/>
<wire x1="73.66" y1="-2.54" x2="73.66" y2="22.86" width="0.1524" layer="91"/>
<wire x1="73.66" y1="22.86" x2="68.58" y2="27.94" width="0.1524" layer="91"/>
<wire x1="68.58" y1="27.94" x2="48.26" y2="27.94" width="0.1524" layer="91"/>
<pinref part="U$2" gate="G$1" pin="SCL"/>
<wire x1="48.26" y1="-45.72" x2="71.12" y2="-45.72" width="0.1524" layer="91"/>
<wire x1="71.12" y1="-45.72" x2="73.66" y2="-43.18" width="0.1524" layer="91"/>
<pinref part="U$8" gate="G$1" pin="SCL"/>
<wire x1="48.26" y1="-22.86" x2="71.12" y2="-22.86" width="0.1524" layer="91"/>
<wire x1="71.12" y1="-22.86" x2="73.66" y2="-25.4" width="0.1524" layer="91"/>
<junction x="73.66" y="-25.4"/>
<pinref part="U$9" gate="G$1" pin="SCL"/>
<wire x1="48.26" y1="0" x2="71.12" y2="0" width="0.1524" layer="91"/>
<wire x1="71.12" y1="0" x2="73.66" y2="-2.54" width="0.1524" layer="91"/>
<junction x="73.66" y="-2.54"/>
<wire x1="78.74" y1="-15.24" x2="76.2" y2="-15.24" width="0.1524" layer="91"/>
<wire x1="76.2" y1="-15.24" x2="73.66" y2="-12.7" width="0.1524" layer="91"/>
<junction x="73.66" y="-12.7"/>
</segment>
</net>
<net name="N$12" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="PB11"/>
<pinref part="U$3" gate="G$1" pin="SDA"/>
<wire x1="48.26" y1="22.86" x2="66.04" y2="22.86" width="0.1524" layer="91"/>
<wire x1="66.04" y1="22.86" x2="68.58" y2="20.32" width="0.1524" layer="91"/>
<wire x1="68.58" y1="20.32" x2="68.58" y2="-7.62" width="0.1524" layer="91"/>
<pinref part="U$2" gate="G$1" pin="SDA"/>
<wire x1="68.58" y1="-7.62" x2="68.58" y2="-17.78" width="0.1524" layer="91"/>
<wire x1="68.58" y1="-17.78" x2="68.58" y2="-30.48" width="0.1524" layer="91"/>
<wire x1="68.58" y1="-30.48" x2="68.58" y2="-48.26" width="0.1524" layer="91"/>
<wire x1="48.26" y1="-50.8" x2="66.04" y2="-50.8" width="0.1524" layer="91"/>
<wire x1="66.04" y1="-50.8" x2="68.58" y2="-48.26" width="0.1524" layer="91"/>
<pinref part="U$8" gate="G$1" pin="SDA"/>
<wire x1="48.26" y1="-27.94" x2="66.04" y2="-27.94" width="0.1524" layer="91"/>
<wire x1="66.04" y1="-27.94" x2="68.58" y2="-30.48" width="0.1524" layer="91"/>
<junction x="68.58" y="-30.48"/>
<pinref part="U$9" gate="G$1" pin="SDA"/>
<wire x1="48.26" y1="-5.08" x2="66.04" y2="-5.08" width="0.1524" layer="91"/>
<wire x1="66.04" y1="-5.08" x2="68.58" y2="-7.62" width="0.1524" layer="91"/>
<junction x="68.58" y="-7.62"/>
<wire x1="78.74" y1="-20.32" x2="71.12" y2="-20.32" width="0.1524" layer="91"/>
<wire x1="71.12" y1="-20.32" x2="68.58" y2="-17.78" width="0.1524" layer="91"/>
<junction x="68.58" y="-17.78"/>
</segment>
</net>
<net name="SWDIO_0" class="0">
<segment>
<pinref part="U$5" gate="G$1" pin="A2"/>
<wire x1="-154.94" y1="-25.4" x2="-167.64" y2="-25.4" width="0.1524" layer="91"/>
<label x="-167.64" y="-25.4" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="SWDIO"/>
<wire x1="96.52" y1="48.26" x2="96.52" y2="58.42" width="0.1524" layer="91"/>
<wire x1="96.52" y1="58.42" x2="99.06" y2="60.96" width="0.1524" layer="91"/>
<wire x1="99.06" y1="60.96" x2="114.3" y2="60.96" width="0.1524" layer="91"/>
<label x="104.14" y="60.96" size="1.778" layer="95"/>
</segment>
</net>
<net name="SWCLK_0" class="0">
<segment>
<pinref part="U$5" gate="G$1" pin="A3"/>
<wire x1="-154.94" y1="-27.94" x2="-167.64" y2="-27.94" width="0.1524" layer="91"/>
<label x="-167.64" y="-27.94" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="SWCLK"/>
<wire x1="101.6" y1="48.26" x2="101.6" y2="55.88" width="0.1524" layer="91"/>
<wire x1="101.6" y1="55.88" x2="104.14" y2="58.42" width="0.1524" layer="91"/>
<wire x1="104.14" y1="58.42" x2="114.3" y2="58.42" width="0.1524" layer="91"/>
<label x="104.14" y="58.42" size="1.778" layer="95"/>
</segment>
</net>
<net name="SWCLK_1" class="0">
<segment>
<pinref part="U$5" gate="G$1" pin="A10"/>
<wire x1="-154.94" y1="-45.72" x2="-167.64" y2="-45.72" width="0.1524" layer="91"/>
<label x="-167.64" y="-45.72" size="1.778" layer="95"/>
</segment>
<segment>
<wire x1="119.38" y1="-71.12" x2="132.08" y2="-71.12" width="0.1524" layer="91"/>
<label x="119.38" y="-71.12" size="1.778" layer="95"/>
<pinref part="P3" gate="G$1" pin="2"/>
</segment>
</net>
<net name="SWDIO_1" class="0">
<segment>
<pinref part="U$5" gate="G$1" pin="A11"/>
<wire x1="-154.94" y1="-48.26" x2="-167.64" y2="-48.26" width="0.1524" layer="91"/>
<label x="-167.64" y="-48.26" size="1.778" layer="95"/>
</segment>
<segment>
<wire x1="132.08" y1="-68.58" x2="119.38" y2="-68.58" width="0.1524" layer="91"/>
<label x="119.38" y="-68.58" size="1.778" layer="95"/>
<pinref part="P3" gate="G$1" pin="1"/>
</segment>
</net>
<net name="7.4V" class="0">
<segment>
<pinref part="P2" gate="G$1" pin="2"/>
<wire x1="228.6" y1="-68.58" x2="215.9" y2="-68.58" width="0.1524" layer="91"/>
<label x="215.9" y="-68.58" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$3" gate="G$1" pin="VIN-"/>
<wire x1="48.26" y1="33.02" x2="66.04" y2="33.02" width="0.1524" layer="91"/>
<label x="55.88" y="33.02" size="1.778" layer="95"/>
</segment>
</net>
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
