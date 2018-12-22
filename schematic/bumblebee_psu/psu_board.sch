<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="7.6.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
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
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="transistor-power">
<description>&lt;b&gt;Power Transistors&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="TO220BH">
<description>&lt;b&gt;Molded Package&lt;/b&gt;&lt;p&gt;
grid 2.54 mm</description>
<wire x1="-5.207" y1="-1.27" x2="5.207" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="5.207" y1="14.605" x2="-5.207" y2="14.605" width="0.1524" layer="21"/>
<wire x1="5.207" y1="-1.27" x2="5.207" y2="11.176" width="0.1524" layer="21"/>
<wire x1="5.207" y1="11.176" x2="4.318" y2="11.176" width="0.1524" layer="21"/>
<wire x1="4.318" y1="11.176" x2="4.318" y2="12.7" width="0.1524" layer="21"/>
<wire x1="4.318" y1="12.7" x2="5.207" y2="12.7" width="0.1524" layer="21"/>
<wire x1="5.207" y1="12.7" x2="5.207" y2="14.605" width="0.1524" layer="21"/>
<wire x1="-5.207" y1="-1.27" x2="-5.207" y2="11.176" width="0.1524" layer="21"/>
<wire x1="-5.207" y1="11.176" x2="-4.318" y2="11.176" width="0.1524" layer="21"/>
<wire x1="-4.318" y1="11.176" x2="-4.318" y2="12.7" width="0.1524" layer="21"/>
<wire x1="-4.318" y1="12.7" x2="-5.207" y2="12.7" width="0.1524" layer="21"/>
<wire x1="-5.207" y1="12.7" x2="-5.207" y2="14.605" width="0.1524" layer="21"/>
<wire x1="-4.572" y1="-0.635" x2="4.572" y2="-0.635" width="0.0508" layer="21"/>
<wire x1="4.572" y1="7.62" x2="4.572" y2="-0.635" width="0.0508" layer="21"/>
<wire x1="4.572" y1="7.62" x2="-4.572" y2="7.62" width="0.0508" layer="21"/>
<wire x1="-4.572" y1="-0.635" x2="-4.572" y2="7.62" width="0.0508" layer="21"/>
<circle x="0" y="11.176" radius="1.8034" width="0.1524" layer="21"/>
<circle x="0" y="11.176" radius="4.191" width="0" layer="42"/>
<circle x="0" y="11.176" radius="4.191" width="0" layer="43"/>
<pad name="G" x="-2.54" y="-6.35" drill="1.1176" shape="long" rot="R90"/>
<pad name="D" x="0" y="-6.35" drill="1.1176" shape="long" rot="R90"/>
<pad name="S" x="2.54" y="-6.35" drill="1.1176" shape="long" rot="R90"/>
<text x="-3.81" y="5.207" size="1.778" layer="25" ratio="10">&gt;NAME</text>
<text x="-3.937" y="2.54" size="1.778" layer="27" ratio="10">&gt;VALUE</text>
<text x="-4.445" y="7.874" size="1.016" layer="21" ratio="10">A17,5mm</text>
<rectangle x1="2.159" y1="-4.699" x2="2.921" y2="-4.064" layer="21"/>
<rectangle x1="-0.381" y1="-4.699" x2="0.381" y2="-4.064" layer="21"/>
<rectangle x1="-2.921" y1="-4.699" x2="-2.159" y2="-4.064" layer="21"/>
<rectangle x1="-3.175" y1="-4.064" x2="-1.905" y2="-1.27" layer="21"/>
<rectangle x1="-0.635" y1="-4.064" x2="0.635" y2="-1.27" layer="21"/>
<rectangle x1="1.905" y1="-4.064" x2="3.175" y2="-1.27" layer="21"/>
<rectangle x1="-2.921" y1="-6.604" x2="-2.159" y2="-4.699" layer="51"/>
<rectangle x1="-0.381" y1="-6.604" x2="0.381" y2="-4.699" layer="51"/>
<rectangle x1="2.159" y1="-6.604" x2="2.921" y2="-4.699" layer="51"/>
<hole x="0" y="11.176" drill="3.302"/>
</package>
</packages>
<symbols>
<symbol name="HEXFET_N">
<wire x1="-1.1176" y1="2.413" x2="-1.1176" y2="-2.54" width="0.254" layer="94"/>
<wire x1="-1.1176" y1="-2.54" x2="-2.54" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="2.54" y1="2.54" x2="2.54" y2="1.905" width="0.1524" layer="94"/>
<wire x1="2.54" y1="0" x2="2.54" y2="-1.905" width="0.1524" layer="94"/>
<wire x1="0.508" y1="-1.905" x2="2.54" y2="-1.905" width="0.1524" layer="94"/>
<wire x1="2.54" y1="-1.905" x2="2.54" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="1.651" y1="0" x2="2.54" y2="0" width="0.1524" layer="94"/>
<wire x1="3.302" y1="0.508" x2="3.81" y2="0.508" width="0.1524" layer="94"/>
<wire x1="3.81" y1="0.508" x2="4.318" y2="0.508" width="0.1524" layer="94"/>
<wire x1="3.81" y1="1.905" x2="2.54" y2="1.905" width="0.1524" layer="94"/>
<wire x1="2.54" y1="1.905" x2="0.5334" y2="1.905" width="0.1524" layer="94"/>
<wire x1="3.81" y1="0.508" x2="3.81" y2="1.905" width="0.1524" layer="94"/>
<wire x1="3.81" y1="-1.905" x2="3.81" y2="-0.127" width="0.1524" layer="94"/>
<wire x1="3.81" y1="-1.905" x2="2.54" y2="-1.905" width="0.1524" layer="94"/>
<circle x="2.54" y="-1.905" radius="0.127" width="0.4064" layer="94"/>
<text x="6.35" y="2.54" size="1.778" layer="95">&gt;NAME</text>
<text x="6.35" y="0" size="1.778" layer="96">&gt;VALUE</text>
<rectangle x1="-0.254" y1="-2.54" x2="0.508" y2="-1.27" layer="94"/>
<rectangle x1="-0.254" y1="1.27" x2="0.508" y2="2.54" layer="94"/>
<rectangle x1="-0.254" y1="-0.889" x2="0.508" y2="0.889" layer="94"/>
<pin name="G" x="-2.54" y="-2.54" visible="off" length="point" direction="pas"/>
<pin name="D" x="2.54" y="5.08" visible="off" length="short" direction="pas" rot="R270"/>
<pin name="S" x="2.54" y="-5.08" visible="off" length="short" direction="pas" rot="R90"/>
<polygon width="0.1524" layer="94">
<vertex x="0.508" y="0"/>
<vertex x="1.778" y="-0.508"/>
<vertex x="1.778" y="0.508"/>
</polygon>
<polygon width="0.1524" layer="94">
<vertex x="3.81" y="0.508"/>
<vertex x="3.302" y="-0.254"/>
<vertex x="4.318" y="-0.254"/>
</polygon>
</symbol>
</symbols>
<devicesets>
<deviceset name="IRFI540NPBF" prefix="Q">
<description>&lt;b&gt;HEXFET Power MOISFET&lt;/b&gt;&lt;p&gt;
VDSS = 100V, RDS(on) = 0.052 Ohm, ID = 20A, VGS(th) = 2.0 -- 4.0V&lt;br&gt;

Source: http://www.irf.com/product-info/datasheets/data/irfi540npbf.pdf</description>
<gates>
<gate name="G$1" symbol="HEXFET_N" x="0" y="0"/>
</gates>
<devices>
<device name="" package="TO220BH">
<connects>
<connect gate="G$1" pin="D" pad="D"/>
<connect gate="G$1" pin="G" pad="G"/>
<connect gate="G$1" pin="S" pad="S"/>
</connects>
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
<library name="supply1">
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
<symbol name="VCC">
<wire x1="1.27" y1="-1.905" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="-1.905" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="VCC" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
<symbol name="GND">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="VCC" prefix="P+">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="VCC" symbol="VCC" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="GND" prefix="GND">
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
<library name="bluepill">
<packages>
<package name="BLUEPIL">
<description>Microcontroller from st micro on board</description>
<pad name="G0" x="-24.13" y="7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="G1" x="-21.59" y="7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="3V3_0" x="-19.05" y="7.62" drill="0.8" shape="long" rot="R90"/>
<pad name="R" x="-16.51" y="7.62" drill="0.8" shape="long" rot="R90"/>
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
<pad name="G2" x="21.59" y="-7.62" drill="0.8" shape="long" rot="R90"/>
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
</package>
</packages>
<symbols>
<symbol name="BLUEPILL">
<description>bluepill board</description>
<pin name="G" x="10.16" y="53.34" length="middle" rot="R270"/>
<pin name="PB0" x="-27.94" y="33.02" length="middle"/>
<pin name="PB1" x="-27.94" y="27.94" length="middle"/>
<pin name="PB3" x="-27.94" y="17.78" length="middle"/>
<pin name="PB4" x="-27.94" y="12.7" length="middle"/>
<pin name="PB5" x="-27.94" y="7.62" length="middle"/>
<pin name="PB6" x="-27.94" y="2.54" length="middle"/>
<pin name="PB7" x="-27.94" y="-2.54" length="middle"/>
<pin name="PB8" x="-27.94" y="-7.62" length="middle"/>
<pin name="PB9" x="-27.94" y="-12.7" length="middle"/>
<pin name="PB10" x="-27.94" y="-17.78" length="middle"/>
<pin name="PB11" x="-27.94" y="-22.86" length="middle"/>
<pin name="PB12" x="-27.94" y="-27.94" length="middle"/>
<pin name="PB13" x="-27.94" y="-33.02" length="middle"/>
<pin name="PB14" x="-27.94" y="-38.1" length="middle"/>
<pin name="PB15" x="-27.94" y="-43.18" length="middle"/>
<pin name="R" x="5.08" y="53.34" length="middle" rot="R270"/>
<pin name="5V" x="0" y="53.34" length="middle" rot="R270"/>
<pin name="3V3" x="-5.08" y="53.34" length="middle" rot="R270"/>
<pin name="VBAT" x="-10.16" y="53.34" length="middle" rot="R270"/>
<pin name="PA0" x="27.94" y="33.02" length="middle" rot="R180"/>
<pin name="PA1" x="27.94" y="27.94" length="middle" rot="R180"/>
<pin name="PA2" x="27.94" y="22.86" length="middle" rot="R180"/>
<pin name="PA3" x="27.94" y="17.78" length="middle" rot="R180"/>
<pin name="PA4" x="27.94" y="12.7" length="middle" rot="R180"/>
<pin name="PA5" x="27.94" y="7.62" length="middle" rot="R180"/>
<pin name="PA6" x="27.94" y="2.54" length="middle" rot="R180"/>
<pin name="PA7" x="27.94" y="-2.54" length="middle" rot="R180"/>
<pin name="PA8" x="27.94" y="-7.62" length="middle" rot="R180"/>
<pin name="PA9" x="27.94" y="-12.7" length="middle" rot="R180"/>
<pin name="PA10" x="27.94" y="-17.78" length="middle" rot="R180"/>
<pin name="PA11" x="27.94" y="-22.86" length="middle" rot="R180"/>
<pin name="PA12" x="27.94" y="-27.94" length="middle" rot="R180"/>
<pin name="PA15" x="27.94" y="-43.18" length="middle" rot="R180"/>
<pin name="PC13" x="-5.08" y="-60.96" length="middle" rot="R90"/>
<pin name="PC14" x="0" y="-60.96" length="middle" rot="R90"/>
<pin name="PC15" x="5.08" y="-60.96" length="middle" rot="R90"/>
<wire x1="-22.86" y1="48.26" x2="-22.86" y2="-55.88" width="0.254" layer="94"/>
<wire x1="-22.86" y1="-55.88" x2="22.86" y2="-55.88" width="0.254" layer="94"/>
<wire x1="22.86" y1="-55.88" x2="22.86" y2="48.26" width="0.254" layer="94"/>
<wire x1="22.86" y1="48.26" x2="-22.86" y2="48.26" width="0.254" layer="94"/>
<text x="17.78" y="53.34" size="1.27" layer="95">&gt;NAME</text>
<text x="17.78" y="50.8" size="1.27" layer="96">&gt;VALUE</text>
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
<connect gate="G$1" pin="3V3" pad="3V3_0 3V3_1"/>
<connect gate="G$1" pin="5V" pad="5V"/>
<connect gate="G$1" pin="G" pad="G0 G1 G2"/>
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
<connect gate="G$1" pin="R" pad="R"/>
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
<part name="Q1" library="transistor-power" deviceset="IRFI540NPBF" device=""/>
<part name="Q2" library="transistor-power" deviceset="IRFI540NPBF" device=""/>
<part name="Q3" library="transistor-power" deviceset="IRFI540NPBF" device=""/>
<part name="Q4" library="transistor-power" deviceset="IRFI540NPBF" device=""/>
<part name="P1" library="con-jst-eh" deviceset="B3B-EH-A" device=""/>
<part name="P2" library="con-jst-eh" deviceset="B5B-EH-A" device=""/>
<part name="P+1" library="supply1" deviceset="VCC" device=""/>
<part name="GND1" library="supply1" deviceset="GND" device=""/>
<part name="GND2" library="supply1" deviceset="GND" device=""/>
<part name="U$1" library="bluepill" deviceset="BLUEPILL" device="THEONLYONE"/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="Q1" gate="G$1" x="45.72" y="63.5"/>
<instance part="Q2" gate="G$1" x="83.82" y="63.5"/>
<instance part="Q3" gate="G$1" x="121.92" y="63.5"/>
<instance part="Q4" gate="G$1" x="-25.4" y="30.48"/>
<instance part="P1" gate="G$1" x="-38.1" y="86.36" rot="R180"/>
<instance part="P2" gate="G$1" x="104.14" y="27.94"/>
<instance part="P+1" gate="VCC" x="-15.24" y="101.6"/>
<instance part="GND1" gate="1" x="-22.86" y="12.7"/>
<instance part="GND2" gate="1" x="-15.24" y="76.2"/>
<instance part="U$1" gate="G$1" x="233.68" y="-12.7"/>
</instances>
<busses>
</busses>
<nets>
<net name="GND" class="0">
<segment>
<pinref part="P1" gate="G$1" pin="1"/>
<wire x1="-33.02" y1="83.82" x2="-15.24" y2="83.82" width="0.1524" layer="91"/>
<label x="-22.86" y="78.74" size="1.778" layer="95"/>
<pinref part="GND2" gate="1" pin="GND"/>
<wire x1="-15.24" y1="83.82" x2="-15.24" y2="78.74" width="0.1524" layer="91"/>
</segment>
<segment>
<wire x1="-22.86" y1="25.4" x2="-22.86" y2="15.24" width="0.1524" layer="91"/>
<pinref part="Q4" gate="G$1" pin="S"/>
<label x="-12.7" y="20.32" size="1.778" layer="95" rot="R180"/>
<pinref part="GND1" gate="1" pin="GND"/>
</segment>
</net>
<net name="VCC" class="0">
<segment>
<pinref part="P1" gate="G$1" pin="3"/>
<wire x1="-33.02" y1="88.9" x2="-15.24" y2="88.9" width="0.1524" layer="91"/>
<label x="-22.86" y="91.44" size="1.778" layer="95"/>
<pinref part="P+1" gate="VCC" pin="VCC"/>
<wire x1="-15.24" y1="88.9" x2="-15.24" y2="99.06" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
