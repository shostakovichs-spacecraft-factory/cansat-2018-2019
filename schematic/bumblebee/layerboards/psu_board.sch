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
<symbol name="INA">
<pin name="VIN-_1" x="-2.54" y="17.78" length="middle" rot="R270"/>
<pin name="VIN+_1" x="2.54" y="17.78" length="middle" rot="R270"/>
<pin name="SDA" x="2.54" y="-12.7" length="middle" rot="R90"/>
<pin name="SCL" x="-2.54" y="-12.7" length="middle" rot="R90"/>
<pin name="GND" x="-7.62" y="-12.7" length="middle" rot="R90"/>
<pin name="VCC" x="-12.7" y="-12.7" length="middle" rot="R90"/>
<pin name="VIN-_0" x="7.62" y="-12.7" length="middle" rot="R90"/>
<pin name="VIN+_0" x="12.7" y="-12.7" length="middle" rot="R90"/>
<wire x1="-15.24" y1="12.7" x2="-15.24" y2="-7.62" width="0.254" layer="94"/>
<wire x1="-15.24" y1="-7.62" x2="15.24" y2="-7.62" width="0.254" layer="94"/>
<wire x1="15.24" y1="-7.62" x2="15.24" y2="12.7" width="0.254" layer="94"/>
<wire x1="-15.24" y1="12.7" x2="15.24" y2="12.7" width="0.254" layer="94"/>
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
<connect gate="G$1" pin="VIN+_0" pad="VIN+_0"/>
<connect gate="G$1" pin="VIN+_1" pad="VIN+_1"/>
<connect gate="G$1" pin="VIN-_0" pad="VIN-_0"/>
<connect gate="G$1" pin="VIN-_1" pad="VIN-_1"/>
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
<part name="GND3" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
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
<part name="U$2" library="bluepill" deviceset="INA" device=""/>
<part name="GND7" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="U$3" library="bluepill" deviceset="INA" device=""/>
<part name="GND8" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="U$4" library="MCP2551" deviceset="MCP2551" device=""/>
<part name="GND9" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="R9" library="ngspice-simulation" library_urn="urn:adsk.eagle:library:527439" deviceset="R" device=""/>
<part name="GND10" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="G2" library="battery" library_urn="urn:adsk.eagle:library:109" deviceset="SL-160AA/PT" device="" package3d_urn="urn:adsk.eagle:package:4615/1"/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="G1" gate="G$1" x="-116.84" y="-50.8" smashed="yes">
<attribute name="NAME" x="-116.84" y="-47.625" size="1.778" layer="95"/>
</instance>
<instance part="GND3" gate="1" x="-121.92" y="-55.88" smashed="yes">
<attribute name="VALUE" x="-124.46" y="-58.42" size="1.778" layer="96"/>
</instance>
<instance part="DC1" gate="G$1" x="-78.74" y="-30.48" smashed="yes">
<attribute name="NAME" x="-88.9" y="-24.765" size="1.778" layer="95"/>
<attribute name="VALUE" x="-88.9" y="-40.64" size="1.778" layer="96"/>
</instance>
<instance part="GND4" gate="1" x="-78.74" y="-43.18" smashed="yes">
<attribute name="VALUE" x="-81.28" y="-45.72" size="1.778" layer="96"/>
</instance>
<instance part="DC2" gate="G$1" x="-78.74" y="-53.34" smashed="yes">
<attribute name="NAME" x="-88.9" y="-47.625" size="1.778" layer="95"/>
<attribute name="VALUE" x="-88.9" y="-63.5" size="1.778" layer="96"/>
</instance>
<instance part="GND5" gate="1" x="-78.74" y="-66.04" smashed="yes">
<attribute name="VALUE" x="-81.28" y="-68.58" size="1.778" layer="96"/>
</instance>
<instance part="DC3" gate="G$1" x="-78.74" y="-76.2" smashed="yes">
<attribute name="NAME" x="-88.9" y="-70.485" size="1.778" layer="95"/>
<attribute name="VALUE" x="-88.9" y="-86.36" size="1.778" layer="96"/>
</instance>
<instance part="GND6" gate="1" x="-78.74" y="-88.9" smashed="yes">
<attribute name="VALUE" x="-81.28" y="-91.44" size="1.778" layer="96"/>
</instance>
<instance part="Q1" gate="G$1" x="-30.48" y="0" smashed="yes">
<attribute name="NAME" x="-25.4" y="2.54" size="1.778" layer="95"/>
<attribute name="VALUE" x="-25.4" y="0" size="1.778" layer="96"/>
</instance>
<instance part="R1" gate="G$1" x="-35.56" y="2.54" smashed="yes" rot="R90">
<attribute name="NAME" x="-38.1" y="0" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="-31.75" y="0" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="Q2" gate="G$1" x="-38.1" y="-7.62" smashed="yes">
<attribute name="NAME" x="-30.48" y="-5.08" size="1.778" layer="95"/>
<attribute name="VALUE" x="-30.48" y="-7.62" size="1.778" layer="96"/>
</instance>
<instance part="R2" gate="G$1" x="-43.18" y="-5.08" smashed="yes" rot="R90">
<attribute name="NAME" x="-45.72" y="-7.62" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="-39.37" y="-7.62" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="GND1" gate="1" x="-35.56" y="-15.24" smashed="yes">
<attribute name="VALUE" x="-38.1" y="-17.78" size="1.778" layer="96"/>
</instance>
<instance part="Q3" gate="G$1" x="-30.48" y="-27.94" smashed="yes">
<attribute name="NAME" x="-25.4" y="-25.4" size="1.778" layer="95"/>
<attribute name="VALUE" x="-25.4" y="-27.94" size="1.778" layer="96"/>
</instance>
<instance part="R3" gate="G$1" x="-35.56" y="-25.4" smashed="yes" rot="R90">
<attribute name="NAME" x="-38.1" y="-27.94" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="-31.75" y="-27.94" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="Q4" gate="G$1" x="-38.1" y="-35.56" smashed="yes">
<attribute name="NAME" x="-30.48" y="-35.56" size="1.778" layer="95"/>
<attribute name="VALUE" x="-30.48" y="-38.1" size="1.778" layer="96"/>
</instance>
<instance part="R4" gate="G$1" x="-43.18" y="-33.02" smashed="yes" rot="R90">
<attribute name="NAME" x="-45.72" y="-35.56" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="-39.37" y="-35.56" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="Q5" gate="G$1" x="-30.48" y="-50.8" smashed="yes">
<attribute name="NAME" x="-25.4" y="-48.26" size="1.778" layer="95"/>
<attribute name="VALUE" x="-25.4" y="-50.8" size="1.778" layer="96"/>
</instance>
<instance part="R5" gate="G$1" x="-35.56" y="-48.26" smashed="yes" rot="R90">
<attribute name="NAME" x="-38.1" y="-50.8" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="-31.75" y="-50.8" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="Q6" gate="G$1" x="-38.1" y="-58.42" smashed="yes">
<attribute name="NAME" x="-30.48" y="-58.42" size="1.778" layer="95"/>
<attribute name="VALUE" x="-30.48" y="-60.96" size="1.778" layer="96"/>
</instance>
<instance part="R6" gate="G$1" x="-43.18" y="-55.88" smashed="yes" rot="R90">
<attribute name="NAME" x="-45.72" y="-58.42" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="-39.37" y="-58.42" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="Q7" gate="G$1" x="-30.48" y="-73.66" smashed="yes">
<attribute name="NAME" x="-25.4" y="-71.12" size="1.778" layer="95"/>
<attribute name="VALUE" x="-25.4" y="-73.66" size="1.778" layer="96"/>
</instance>
<instance part="R7" gate="G$1" x="-35.56" y="-71.12" smashed="yes" rot="R90">
<attribute name="NAME" x="-38.1" y="-73.66" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="-31.75" y="-73.66" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="Q8" gate="G$1" x="-38.1" y="-81.28" smashed="yes">
<attribute name="NAME" x="-30.48" y="-81.28" size="1.778" layer="95"/>
<attribute name="VALUE" x="-30.48" y="-83.82" size="1.778" layer="96"/>
</instance>
<instance part="R8" gate="G$1" x="-43.18" y="-78.74" smashed="yes" rot="R90">
<attribute name="NAME" x="-45.72" y="-81.28" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="-39.37" y="-81.28" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="U$1" gate="G$1" x="66.04" y="-40.64" smashed="yes">
<attribute name="NAME" x="76.2" y="10.16" size="1.27" layer="95"/>
<attribute name="VALUE" x="76.2" y="7.62" size="1.27" layer="96"/>
</instance>
<instance part="GND2" gate="1" x="99.06" y="0" smashed="yes">
<attribute name="VALUE" x="96.52" y="-2.54" size="1.778" layer="96"/>
</instance>
<instance part="U$2" gate="G$1" x="7.62" y="-12.7" smashed="yes"/>
<instance part="GND7" gate="1" x="0" y="-30.48" smashed="yes">
<attribute name="VALUE" x="-2.54" y="-33.02" size="1.778" layer="96"/>
</instance>
<instance part="U$3" gate="G$1" x="7.62" y="-68.58" smashed="yes"/>
<instance part="GND8" gate="1" x="0" y="-86.36" smashed="yes">
<attribute name="VALUE" x="-2.54" y="-88.9" size="1.778" layer="96"/>
</instance>
<instance part="U$4" gate="G$1" x="139.7" y="-71.12" smashed="yes"/>
<instance part="GND9" gate="1" x="111.76" y="-71.12" smashed="yes">
<attribute name="VALUE" x="109.22" y="-73.66" size="1.778" layer="96"/>
</instance>
<instance part="R9" gate="G$1" x="170.18" y="-68.58" smashed="yes">
<attribute name="NAME" x="167.64" y="-66.04" size="1.778" layer="95"/>
<attribute name="VALUE" x="167.64" y="-72.39" size="1.778" layer="96"/>
</instance>
<instance part="GND10" gate="1" x="182.88" y="-71.12" smashed="yes">
<attribute name="VALUE" x="180.34" y="-73.66" size="1.778" layer="96"/>
</instance>
<instance part="G2" gate="G$1" x="-106.68" y="-50.8" smashed="yes">
<attribute name="NAME" x="-106.68" y="-47.625" size="1.778" layer="95"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="GND" class="0">
<segment>
<pinref part="G1" gate="G$1" pin="-"/>
<pinref part="GND3" gate="1" pin="GND"/>
<wire x1="-121.92" y1="-50.8" x2="-121.92" y2="-53.34" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND4" gate="1" pin="GND"/>
<pinref part="DC1" gate="G$1" pin="-VIN"/>
<wire x1="-78.74" y1="-40.64" x2="-91.44" y2="-40.64" width="0.1524" layer="91"/>
<wire x1="-91.44" y1="-40.64" x2="-91.44" y2="-33.02" width="0.1524" layer="91"/>
<wire x1="-78.74" y1="-40.64" x2="-66.04" y2="-40.64" width="0.1524" layer="91"/>
<junction x="-78.74" y="-40.64"/>
<pinref part="DC1" gate="G$1" pin="-VOUT"/>
<wire x1="-66.04" y1="-40.64" x2="-66.04" y2="-33.02" width="0.1524" layer="91"/>
<pinref part="Q4" gate="G$1" pin="S"/>
<wire x1="-66.04" y1="-40.64" x2="-35.56" y2="-40.64" width="0.1524" layer="91"/>
<junction x="-66.04" y="-40.64"/>
</segment>
<segment>
<pinref part="GND5" gate="1" pin="GND"/>
<pinref part="DC2" gate="G$1" pin="-VIN"/>
<wire x1="-78.74" y1="-63.5" x2="-91.44" y2="-63.5" width="0.1524" layer="91"/>
<wire x1="-91.44" y1="-63.5" x2="-91.44" y2="-55.88" width="0.1524" layer="91"/>
<wire x1="-78.74" y1="-63.5" x2="-66.04" y2="-63.5" width="0.1524" layer="91"/>
<junction x="-78.74" y="-63.5"/>
<pinref part="DC2" gate="G$1" pin="-VOUT"/>
<wire x1="-66.04" y1="-63.5" x2="-66.04" y2="-55.88" width="0.1524" layer="91"/>
<pinref part="Q6" gate="G$1" pin="S"/>
<wire x1="-66.04" y1="-63.5" x2="-35.56" y2="-63.5" width="0.1524" layer="91"/>
<junction x="-66.04" y="-63.5"/>
</segment>
<segment>
<pinref part="GND6" gate="1" pin="GND"/>
<pinref part="DC3" gate="G$1" pin="-VIN"/>
<wire x1="-78.74" y1="-86.36" x2="-91.44" y2="-86.36" width="0.1524" layer="91"/>
<wire x1="-91.44" y1="-86.36" x2="-91.44" y2="-78.74" width="0.1524" layer="91"/>
<wire x1="-78.74" y1="-86.36" x2="-66.04" y2="-86.36" width="0.1524" layer="91"/>
<junction x="-78.74" y="-86.36"/>
<pinref part="DC3" gate="G$1" pin="-VOUT"/>
<wire x1="-66.04" y1="-86.36" x2="-66.04" y2="-78.74" width="0.1524" layer="91"/>
<pinref part="Q8" gate="G$1" pin="S"/>
<wire x1="-66.04" y1="-86.36" x2="-35.56" y2="-86.36" width="0.1524" layer="91"/>
<junction x="-66.04" y="-86.36"/>
</segment>
<segment>
<pinref part="Q2" gate="G$1" pin="S"/>
<pinref part="GND1" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="GND"/>
<pinref part="GND2" gate="1" pin="GND"/>
<wire x1="86.36" y1="2.54" x2="99.06" y2="2.54" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="U$2" gate="G$1" pin="GND"/>
<pinref part="GND7" gate="1" pin="GND"/>
<wire x1="0" y1="-27.94" x2="0" y2="-25.4" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="U$3" gate="G$1" pin="GND"/>
<pinref part="GND8" gate="1" pin="GND"/>
<wire x1="0" y1="-83.82" x2="0" y2="-81.28" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND9" gate="1" pin="GND"/>
<wire x1="111.76" y1="-68.58" x2="121.92" y2="-68.58" width="0.1524" layer="91"/>
<wire x1="121.92" y1="-68.58" x2="124.46" y2="-71.12" width="0.1524" layer="91"/>
<pinref part="U$4" gate="G$1" pin="VSS"/>
</segment>
<segment>
<pinref part="R9" gate="G$1" pin="2"/>
<pinref part="GND10" gate="1" pin="GND"/>
<wire x1="175.26" y1="-68.58" x2="182.88" y2="-68.58" width="0.1524" layer="91"/>
</segment>
</net>
<net name="7.4V" class="0">
<segment>
<pinref part="DC2" gate="G$1" pin="+VIN"/>
<pinref part="DC3" gate="G$1" pin="+VIN"/>
<wire x1="-99.06" y1="-50.8" x2="-91.44" y2="-50.8" width="0.1524" layer="91"/>
<wire x1="-91.44" y1="-73.66" x2="-99.06" y2="-73.66" width="0.1524" layer="91"/>
<wire x1="-99.06" y1="-73.66" x2="-99.06" y2="-50.8" width="0.1524" layer="91"/>
<junction x="-99.06" y="-50.8"/>
<pinref part="DC1" gate="G$1" pin="+VIN"/>
<wire x1="-91.44" y1="-27.94" x2="-99.06" y2="-27.94" width="0.1524" layer="91"/>
<wire x1="-99.06" y1="-27.94" x2="-99.06" y2="-50.8" width="0.1524" layer="91"/>
<pinref part="Q1" gate="G$1" pin="S"/>
<wire x1="-27.94" y1="5.08" x2="-27.94" y2="7.62" width="0.1524" layer="91"/>
<pinref part="R1" gate="G$1" pin="2"/>
<wire x1="-27.94" y1="7.62" x2="-35.56" y2="7.62" width="0.1524" layer="91"/>
<wire x1="-99.06" y1="-27.94" x2="-99.06" y2="7.62" width="0.1524" layer="91"/>
<wire x1="-99.06" y1="7.62" x2="-35.56" y2="7.62" width="0.1524" layer="91"/>
<junction x="-99.06" y="-27.94"/>
<junction x="-35.56" y="7.62"/>
<pinref part="G2" gate="G$1" pin="+"/>
<wire x1="-101.6" y1="-50.8" x2="-99.06" y2="-50.8" width="0.1524" layer="91"/>
</segment>
</net>
<net name="5V_CONTINUOUS" class="0">
<segment>
<pinref part="DC1" gate="G$1" pin="+VOUT"/>
<wire x1="-66.04" y1="-27.94" x2="-60.96" y2="-27.94" width="0.1524" layer="91"/>
<wire x1="-60.96" y1="-27.94" x2="-60.96" y2="-20.32" width="0.1524" layer="91"/>
<pinref part="R4" gate="G$1" pin="2"/>
<wire x1="-43.18" y1="-27.94" x2="-60.96" y2="-27.94" width="0.1524" layer="91"/>
<junction x="-60.96" y="-27.94"/>
<pinref part="Q3" gate="G$1" pin="S"/>
<wire x1="-27.94" y1="-22.86" x2="-27.94" y2="-20.32" width="0.1524" layer="91"/>
<pinref part="R3" gate="G$1" pin="2"/>
<wire x1="-27.94" y1="-20.32" x2="-35.56" y2="-20.32" width="0.1524" layer="91"/>
<junction x="-35.56" y="-20.32"/>
<wire x1="-35.56" y1="-20.32" x2="-60.96" y2="-20.32" width="0.1524" layer="91"/>
<wire x1="-60.96" y1="-20.32" x2="-71.12" y2="-20.32" width="0.1524" layer="91"/>
<junction x="-60.96" y="-20.32"/>
<pinref part="R2" gate="G$1" pin="2"/>
<wire x1="-43.18" y1="0" x2="-71.12" y2="0" width="0.1524" layer="91"/>
<label x="-78.74" y="0" size="1.778" layer="95"/>
<wire x1="-71.12" y1="-20.32" x2="-71.12" y2="0" width="0.1524" layer="91"/>
<wire x1="-71.12" y1="0" x2="-78.74" y2="0" width="0.1524" layer="91"/>
<junction x="-71.12" y="0"/>
<pinref part="U$2" gate="G$1" pin="VCC"/>
<wire x1="-5.08" y1="-25.4" x2="-15.24" y2="-25.4" width="0.1524" layer="91"/>
<wire x1="-15.24" y1="-25.4" x2="-15.24" y2="-20.32" width="0.1524" layer="91"/>
<wire x1="-15.24" y1="-20.32" x2="-27.94" y2="-20.32" width="0.1524" layer="91"/>
<junction x="-27.94" y="-20.32"/>
</segment>
<segment>
<pinref part="R6" gate="G$1" pin="2"/>
<wire x1="-43.18" y1="-50.8" x2="-63.5" y2="-50.8" width="0.1524" layer="91"/>
<label x="-63.5" y="-50.8" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="R8" gate="G$1" pin="2"/>
<wire x1="-43.18" y1="-73.66" x2="-63.5" y2="-73.66" width="0.1524" layer="91"/>
<label x="-63.5" y="-73.66" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="5V"/>
<wire x1="86.36" y1="-7.62" x2="88.9" y2="-7.62" width="0.1524" layer="91"/>
<label x="88.9" y="-7.62" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$3" gate="G$1" pin="VCC"/>
<wire x1="-5.08" y1="-81.28" x2="-10.16" y2="-81.28" width="0.1524" layer="91"/>
<wire x1="-10.16" y1="-81.28" x2="-10.16" y2="-60.96" width="0.1524" layer="91"/>
<label x="-10.16" y="-81.28" size="1.778" layer="95" rot="R90"/>
</segment>
<segment>
<pinref part="U$4" gate="G$1" pin="VDD"/>
<wire x1="124.46" y1="-73.66" x2="121.92" y2="-76.2" width="0.1524" layer="91"/>
<wire x1="121.92" y1="-76.2" x2="99.06" y2="-76.2" width="0.1524" layer="91"/>
<label x="99.06" y="-76.2" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$1" class="0">
<segment>
<pinref part="Q1" gate="G$1" pin="G"/>
<pinref part="R1" gate="G$1" pin="1"/>
<pinref part="Q2" gate="G$1" pin="D"/>
<junction x="-35.56" y="-2.54"/>
</segment>
</net>
<net name="PCTRL_HEATER" class="0">
<segment>
<pinref part="R2" gate="G$1" pin="1"/>
<pinref part="Q2" gate="G$1" pin="G"/>
<wire x1="-43.18" y1="-10.16" x2="-40.64" y2="-10.16" width="0.1524" layer="91"/>
<wire x1="-43.18" y1="-10.16" x2="-63.5" y2="-10.16" width="0.1524" layer="91"/>
<junction x="-43.18" y="-10.16"/>
<label x="-63.5" y="-10.16" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="PA3"/>
<wire x1="86.36" y1="-27.94" x2="88.9" y2="-27.94" width="0.1524" layer="91"/>
<label x="88.9" y="-27.94" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="Q3" gate="G$1" pin="G"/>
<pinref part="R3" gate="G$1" pin="1"/>
<pinref part="Q4" gate="G$1" pin="D"/>
<junction x="-35.56" y="-30.48"/>
</segment>
</net>
<net name="PCTRL_CCU" class="0">
<segment>
<pinref part="R4" gate="G$1" pin="1"/>
<pinref part="Q4" gate="G$1" pin="G"/>
<wire x1="-43.18" y1="-38.1" x2="-40.64" y2="-38.1" width="0.1524" layer="91"/>
<wire x1="-43.18" y1="-38.1" x2="-63.5" y2="-38.1" width="0.1524" layer="91"/>
<junction x="-43.18" y="-38.1"/>
<label x="-63.5" y="-38.1" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="PA0"/>
<wire x1="86.36" y1="-12.7" x2="88.9" y2="-12.7" width="0.1524" layer="91"/>
<label x="88.9" y="-12.7" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="Q5" gate="G$1" pin="G"/>
<pinref part="R5" gate="G$1" pin="1"/>
<pinref part="Q6" gate="G$1" pin="D"/>
<junction x="-35.56" y="-53.34"/>
</segment>
</net>
<net name="PCTRL_SCU" class="0">
<segment>
<pinref part="R6" gate="G$1" pin="1"/>
<pinref part="Q6" gate="G$1" pin="G"/>
<wire x1="-43.18" y1="-60.96" x2="-40.64" y2="-60.96" width="0.1524" layer="91"/>
<wire x1="-43.18" y1="-60.96" x2="-63.5" y2="-60.96" width="0.1524" layer="91"/>
<junction x="-43.18" y="-60.96"/>
<label x="-63.5" y="-60.96" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="PA1"/>
<wire x1="86.36" y1="-17.78" x2="88.9" y2="-17.78" width="0.1524" layer="91"/>
<label x="88.9" y="-17.78" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="DC2" gate="G$1" pin="+VOUT"/>
<wire x1="-66.04" y1="-50.8" x2="-66.04" y2="-43.18" width="0.1524" layer="91"/>
<pinref part="R5" gate="G$1" pin="2"/>
<wire x1="-66.04" y1="-43.18" x2="-35.56" y2="-43.18" width="0.1524" layer="91"/>
<pinref part="Q5" gate="G$1" pin="S"/>
<wire x1="-35.56" y1="-43.18" x2="-27.94" y2="-43.18" width="0.1524" layer="91"/>
<wire x1="-27.94" y1="-43.18" x2="-27.94" y2="-45.72" width="0.1524" layer="91"/>
<junction x="-35.56" y="-43.18"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="Q7" gate="G$1" pin="G"/>
<pinref part="R7" gate="G$1" pin="1"/>
<pinref part="Q8" gate="G$1" pin="D"/>
<junction x="-35.56" y="-76.2"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="R7" gate="G$1" pin="2"/>
<wire x1="-66.04" y1="-66.04" x2="-35.56" y2="-66.04" width="0.1524" layer="91"/>
<pinref part="Q7" gate="G$1" pin="S"/>
<wire x1="-35.56" y1="-66.04" x2="-27.94" y2="-66.04" width="0.1524" layer="91"/>
<wire x1="-27.94" y1="-66.04" x2="-27.94" y2="-68.58" width="0.1524" layer="91"/>
<junction x="-35.56" y="-66.04"/>
<pinref part="DC3" gate="G$1" pin="+VOUT"/>
<wire x1="-66.04" y1="-73.66" x2="-66.04" y2="-66.04" width="0.1524" layer="91"/>
</segment>
</net>
<net name="PCTRL_PCU" class="0">
<segment>
<pinref part="R8" gate="G$1" pin="1"/>
<pinref part="Q8" gate="G$1" pin="G"/>
<wire x1="-43.18" y1="-83.82" x2="-40.64" y2="-83.82" width="0.1524" layer="91"/>
<wire x1="-43.18" y1="-83.82" x2="-63.5" y2="-83.82" width="0.1524" layer="91"/>
<junction x="-43.18" y="-83.82"/>
<label x="-63.5" y="-83.82" size="1.778" layer="95"/>
</segment>
</net>
<net name="PCTRL_ICU" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="PA2"/>
<wire x1="86.36" y1="-22.86" x2="88.9" y2="-22.86" width="0.1524" layer="91"/>
<label x="88.9" y="-22.86" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="Q1" gate="G$1" pin="D"/>
<wire x1="-27.94" y1="-5.08" x2="-15.24" y2="-5.08" width="0.1524" layer="91"/>
<wire x1="-15.24" y1="-5.08" x2="-15.24" y2="12.7" width="0.1524" layer="91"/>
<wire x1="-15.24" y1="12.7" x2="10.16" y2="12.7" width="0.1524" layer="91"/>
<pinref part="U$2" gate="G$1" pin="VIN+_1"/>
<wire x1="10.16" y1="12.7" x2="10.16" y2="5.08" width="0.1524" layer="91"/>
</segment>
</net>
<net name="HEATER" class="0">
<segment>
<pinref part="U$2" gate="G$1" pin="VIN-_1"/>
<wire x1="5.08" y1="5.08" x2="-10.16" y2="5.08" width="0.1524" layer="91"/>
<label x="-10.16" y="5.08" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$9" class="0">
<segment>
<pinref part="Q3" gate="G$1" pin="D"/>
<wire x1="-27.94" y1="-33.02" x2="-17.78" y2="-33.02" width="0.1524" layer="91"/>
<wire x1="-17.78" y1="-33.02" x2="-17.78" y2="-40.64" width="0.1524" layer="91"/>
<wire x1="-17.78" y1="-40.64" x2="20.32" y2="-40.64" width="0.1524" layer="91"/>
<pinref part="U$2" gate="G$1" pin="VIN+_0"/>
<wire x1="20.32" y1="-40.64" x2="20.32" y2="-25.4" width="0.1524" layer="91"/>
</segment>
</net>
<net name="5V_CCU" class="0">
<segment>
<pinref part="U$2" gate="G$1" pin="VIN-_0"/>
<wire x1="15.24" y1="-25.4" x2="15.24" y2="-38.1" width="0.1524" layer="91"/>
<wire x1="15.24" y1="-38.1" x2="5.08" y2="-38.1" width="0.1524" layer="91"/>
<label x="5.08" y="-38.1" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$10" class="0">
<segment>
<wire x1="-17.78" y1="-55.88" x2="-17.78" y2="-43.18" width="0.1524" layer="91"/>
<wire x1="-17.78" y1="-43.18" x2="10.16" y2="-43.18" width="0.1524" layer="91"/>
<pinref part="U$3" gate="G$1" pin="VIN+_1"/>
<wire x1="10.16" y1="-43.18" x2="10.16" y2="-50.8" width="0.1524" layer="91"/>
<pinref part="Q5" gate="G$1" pin="D"/>
<wire x1="-27.94" y1="-55.88" x2="-17.78" y2="-55.88" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$11" class="0">
<segment>
<wire x1="-17.78" y1="-96.52" x2="20.32" y2="-96.52" width="0.1524" layer="91"/>
<pinref part="U$3" gate="G$1" pin="VIN+_0"/>
<wire x1="20.32" y1="-96.52" x2="20.32" y2="-81.28" width="0.1524" layer="91"/>
<wire x1="-17.78" y1="-96.52" x2="-17.78" y2="-78.74" width="0.1524" layer="91"/>
<pinref part="Q7" gate="G$1" pin="D"/>
<wire x1="-17.78" y1="-78.74" x2="-27.94" y2="-78.74" width="0.1524" layer="91"/>
</segment>
</net>
<net name="5V_SCU" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="VIN-_1"/>
<wire x1="5.08" y1="-50.8" x2="-10.16" y2="-50.8" width="0.1524" layer="91"/>
<label x="-10.16" y="-50.8" size="1.778" layer="95"/>
</segment>
</net>
<net name="5V_ICU" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="VIN-_0"/>
<wire x1="15.24" y1="-81.28" x2="15.24" y2="-93.98" width="0.1524" layer="91"/>
<wire x1="15.24" y1="-93.98" x2="5.08" y2="-93.98" width="0.1524" layer="91"/>
<label x="5.08" y="-93.98" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$12" class="0">
<segment>
<pinref part="U$2" gate="G$1" pin="SCL"/>
<wire x1="5.08" y1="-25.4" x2="5.08" y2="-35.56" width="0.1524" layer="91"/>
<wire x1="5.08" y1="-35.56" x2="27.94" y2="-35.56" width="0.1524" layer="91"/>
<pinref part="U$3" gate="G$1" pin="SCL"/>
<wire x1="5.08" y1="-81.28" x2="5.08" y2="-91.44" width="0.1524" layer="91"/>
<wire x1="5.08" y1="-91.44" x2="27.94" y2="-91.44" width="0.1524" layer="91"/>
<wire x1="27.94" y1="-35.56" x2="27.94" y2="-58.42" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="PB10"/>
<wire x1="27.94" y1="-58.42" x2="27.94" y2="-91.44" width="0.1524" layer="91"/>
<wire x1="45.72" y1="-53.34" x2="43.18" y2="-53.34" width="0.1524" layer="91"/>
<wire x1="43.18" y1="-53.34" x2="38.1" y2="-58.42" width="0.1524" layer="91"/>
<wire x1="38.1" y1="-58.42" x2="27.94" y2="-58.42" width="0.1524" layer="91"/>
<junction x="27.94" y="-58.42"/>
</segment>
</net>
<net name="N$13" class="0">
<segment>
<pinref part="U$2" gate="G$1" pin="SDA"/>
<wire x1="10.16" y1="-25.4" x2="10.16" y2="-30.48" width="0.1524" layer="91"/>
<wire x1="10.16" y1="-30.48" x2="33.02" y2="-30.48" width="0.1524" layer="91"/>
<pinref part="U$3" gate="G$1" pin="SDA"/>
<wire x1="10.16" y1="-81.28" x2="10.16" y2="-86.36" width="0.1524" layer="91"/>
<wire x1="10.16" y1="-86.36" x2="33.02" y2="-86.36" width="0.1524" layer="91"/>
<wire x1="33.02" y1="-30.48" x2="33.02" y2="-53.34" width="0.1524" layer="91"/>
<wire x1="33.02" y1="-53.34" x2="33.02" y2="-86.36" width="0.1524" layer="91"/>
<wire x1="33.02" y1="-53.34" x2="38.1" y2="-53.34" width="0.1524" layer="91"/>
<junction x="33.02" y="-53.34"/>
<wire x1="38.1" y1="-53.34" x2="43.18" y2="-58.42" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="PB11"/>
<wire x1="43.18" y1="-58.42" x2="45.72" y2="-58.42" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$14" class="0">
<segment>
<pinref part="U$4" gate="G$1" pin="TXD"/>
<wire x1="124.46" y1="-68.58" x2="121.92" y2="-66.04" width="0.1524" layer="91"/>
<wire x1="121.92" y1="-66.04" x2="106.68" y2="-66.04" width="0.1524" layer="91"/>
<wire x1="106.68" y1="-66.04" x2="104.14" y2="-68.58" width="0.1524" layer="91"/>
<wire x1="104.14" y1="-68.58" x2="91.44" y2="-68.58" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="PA12"/>
<wire x1="86.36" y1="-73.66" x2="91.44" y2="-68.58" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$15" class="0">
<segment>
<pinref part="U$4" gate="G$1" pin="RXD"/>
<wire x1="124.46" y1="-76.2" x2="121.92" y2="-78.74" width="0.1524" layer="91"/>
<wire x1="121.92" y1="-78.74" x2="99.06" y2="-78.74" width="0.1524" layer="91"/>
<wire x1="99.06" y1="-78.74" x2="93.98" y2="-73.66" width="0.1524" layer="91"/>
<wire x1="93.98" y1="-73.66" x2="91.44" y2="-73.66" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="PA11"/>
<wire x1="91.44" y1="-73.66" x2="86.36" y2="-68.58" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$16" class="0">
<segment>
<pinref part="U$4" gate="G$1" pin="RS"/>
<pinref part="R9" gate="G$1" pin="1"/>
<wire x1="165.1" y1="-68.58" x2="157.48" y2="-68.58" width="0.1524" layer="91"/>
</segment>
</net>
<net name="CANH" class="0">
<segment>
<pinref part="U$4" gate="G$1" pin="CANH"/>
<wire x1="157.48" y1="-71.12" x2="177.8" y2="-71.12" width="0.1524" layer="91"/>
<label x="170.18" y="-73.66" size="1.778" layer="95"/>
</segment>
</net>
<net name="CANL" class="0">
<segment>
<pinref part="U$4" gate="G$1" pin="CANL"/>
<label x="160.02" y="-76.2" size="1.778" layer="95"/>
<wire x1="157.48" y1="-73.66" x2="167.64" y2="-73.66" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$17" class="0">
<segment>
<pinref part="G2" gate="G$1" pin="-"/>
<pinref part="G1" gate="G$1" pin="+"/>
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
