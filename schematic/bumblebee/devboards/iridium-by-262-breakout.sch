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
<layer number="20" name="Dimension" color="24" fill="1" visible="no" active="no"/>
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
<library name="iridium-antenna">
<packages>
<package name="BY-IRIDIUM-254">
<description>Also known as APAE1621R2540ABDD1-T</description>
<wire x1="-12.5" y1="6" x2="-12.5" y2="-11" width="0.127" layer="21"/>
<wire x1="-12.5" y1="-11" x2="-8.5" y2="-15" width="0.127" layer="21" curve="90"/>
<wire x1="-8.5" y1="-15" x2="8.5" y2="-15" width="0.127" layer="21"/>
<wire x1="8.5" y1="-15" x2="12.5" y2="-11" width="0.127" layer="21" curve="90"/>
<wire x1="12.5" y1="-11" x2="12.5" y2="6" width="0.127" layer="21"/>
<wire x1="12.5" y1="6" x2="8.5" y2="10" width="0.127" layer="21" curve="90"/>
<wire x1="8.5" y1="10" x2="-8.5" y2="10" width="0.127" layer="21"/>
<wire x1="-8.5" y1="10" x2="-12.5" y2="6" width="0.127" layer="21" curve="90"/>
<wire x1="-10" y1="7" x2="7.5" y2="7" width="0.127" layer="51"/>
<wire x1="10" y1="4.5" x2="10" y2="-12.5" width="0.127" layer="51"/>
<wire x1="10" y1="-12.5" x2="-8" y2="-12.5" width="0.127" layer="51"/>
<wire x1="-10" y1="-10.5" x2="-10" y2="7" width="0.127" layer="51"/>
<wire x1="7.5" y1="7" x2="10" y2="4.5" width="0.127" layer="51"/>
<wire x1="-10" y1="-10.5" x2="-8" y2="-12.5" width="0.127" layer="51"/>
<circle x="0" y="0" radius="2.236065625" width="0.127" layer="51"/>
<pad name="P$1" x="0" y="0" drill="0.9" diameter="2.54"/>
<text x="0" y="-5.08" size="1.27" layer="27" align="center">&gt;Name</text>
</package>
</packages>
<symbols>
<symbol name="BY-IRIDIUM-254">
<description>Also known as APAE1621R2540ABDD1-T</description>
<pin name="P$1" x="0" y="-5.08" visible="off" length="middle" rot="R90"/>
<wire x1="0" y1="0" x2="-5.08" y2="5.08" width="0.254" layer="94"/>
<wire x1="0" y1="5.08" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="5.08" y2="5.08" width="0.254" layer="94"/>
<text x="2.54" y="-2.54" size="1.27" layer="95">&gt;Name</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="BY-IRIDIUM-254">
<description>Also known as APAE1621R2540ABDD1-T</description>
<gates>
<gate name="G$1" symbol="BY-IRIDIUM-254" x="0" y="0"/>
</gates>
<devices>
<device name="" package="BY-IRIDIUM-254">
<connects>
<connect gate="G$1" pin="P$1" pad="P$1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="U.FL-R-SMT_01_">
<packages>
<package name="HRS_U.FL-R-SMT(01)">
<wire x1="-1.3" y1="-1.3" x2="-1.3" y2="-0.87" width="0.127" layer="51"/>
<wire x1="-1.3" y1="-0.87" x2="-1.3" y2="1.3" width="0.127" layer="51"/>
<wire x1="1.3" y1="1.3" x2="1.3" y2="-1.3" width="0.127" layer="51"/>
<circle x="0.01" y="0.01" radius="0.3324125" width="0.127" layer="51"/>
<circle x="0" y="0.01" radius="0.551540625" width="0.127" layer="51"/>
<wire x1="1.38" y1="0.87" x2="1.57" y2="0.87" width="0.127" layer="51"/>
<wire x1="1.57" y1="0.87" x2="1.57" y2="-0.87" width="0.127" layer="51"/>
<wire x1="1.57" y1="-0.87" x2="1.34" y2="-0.87" width="0.127" layer="51"/>
<wire x1="1.34" y1="-0.9" x2="1.34" y2="-0.91" width="0.127" layer="52"/>
<wire x1="-1.57" y1="0.87" x2="-1.57" y2="-0.87" width="0.127" layer="51"/>
<wire x1="-1.57" y1="0.87" x2="-1.33" y2="0.87" width="0.127" layer="51"/>
<wire x1="-1.33" y1="0.87" x2="-1.33" y2="0.88" width="0.127" layer="51"/>
<wire x1="-2.3" y1="1.6" x2="-2.3" y2="-2.4" width="0.05" layer="39"/>
<wire x1="-2.3" y1="-2.4" x2="2.3" y2="-2.4" width="0.05" layer="39"/>
<wire x1="2.3" y1="-2.4" x2="2.3" y2="1.6" width="0.05" layer="39"/>
<wire x1="2.3" y1="1.6" x2="-2.3" y2="1.6" width="0.05" layer="39"/>
<text x="-2.807240625" y="1.604140625" size="1.27143125" layer="25">&gt;NAME</text>
<text x="-3.207040625" y="-3.80835" size="1.272709375" layer="27">&gt;VALUE</text>
<wire x1="-1.3" y1="-1.3" x2="1.3" y2="-1.3" width="0.127" layer="51"/>
<wire x1="-1.3" y1="1.3" x2="1.3" y2="1.3" width="0.127" layer="51"/>
<wire x1="1.3" y1="1.3" x2="-1.3" y2="1.3" width="0.127" layer="21"/>
<wire x1="-1.57" y1="-0.87" x2="-1.3" y2="-0.87" width="0.127" layer="51"/>
<rectangle x1="-0.9030625" y1="-0.96326875" x2="0.9" y2="1.15" layer="41"/>
<smd name="1" x="-1.475" y="0" dx="1.1" dy="2.25" layer="1"/>
<smd name="2" x="1.475" y="0" dx="1.1" dy="2.25" layer="1"/>
<smd name="3" x="0" y="-1.55" dx="1.05" dy="1.1" layer="1"/>
</package>
</packages>
<symbols>
<symbol name="U.FL-R-SMT(01)">
<circle x="0" y="2.54" radius="1.016" width="0.254" layer="94"/>
<wire x1="-1.016" y1="1.524" x2="0" y2="1.524" width="0.254" layer="94"/>
<wire x1="0" y1="1.524" x2="1.016" y2="1.524" width="0.254" layer="94"/>
<wire x1="0" y1="1.524" x2="0" y2="-2.54" width="0.254" layer="94"/>
<circle x="0" y="-2.54" radius="0.254" width="0.254" layer="94"/>
<wire x1="-7.62" y1="2.54" x2="2.54" y2="2.54" width="0.254" layer="94"/>
<wire x1="2.54" y1="-2.54" x2="0" y2="-2.54" width="0.254" layer="94"/>
<text x="-3.81856875" y="4.07313125" size="1.27285" layer="95">&gt;NAME</text>
<text x="-4.32781875" y="-5.6007" size="1.27288125" layer="96">&gt;VALUE</text>
<wire x1="0" y1="-2.54" x2="0" y2="-3.302" width="0.254" layer="94"/>
<wire x1="0" y1="-3.302" x2="-0.762" y2="-3.302" width="0.254" layer="94"/>
<wire x1="0" y1="-3.302" x2="0.762" y2="-3.302" width="0.254" layer="94"/>
<wire x1="-0.762" y1="-3.302" x2="-1.27" y2="-4.064" width="0.254" layer="94"/>
<wire x1="0" y1="-3.302" x2="-0.508" y2="-4.064" width="0.254" layer="94"/>
<wire x1="0.762" y1="-3.302" x2="0.254" y2="-4.064" width="0.254" layer="94"/>
<wire x1="2.6" y1="3.4" x2="2.6" y2="1.7" width="0.254" layer="94"/>
<wire x1="2.6" y1="1.7" x2="4.3" y2="2.5" width="0.254" layer="94"/>
<wire x1="4.3" y1="2.5" x2="2.7" y2="3.4" width="0.254" layer="94"/>
<wire x1="-7.62" y1="-2.54" x2="0" y2="-2.54" width="0.254" layer="94"/>
<wire x1="2.7" y1="-1.7" x2="2.7" y2="-3.4" width="0.254" layer="94"/>
<wire x1="2.7" y1="-3.4" x2="4.4" y2="-2.6" width="0.254" layer="94"/>
<wire x1="4.4" y1="-2.6" x2="2.8" y2="-1.7" width="0.254" layer="94"/>
<pin name="SIG" x="-10.16" y="2.54" length="short" direction="pas"/>
<pin name="GND" x="-10.16" y="-2.54" length="short" direction="pas"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="U.FL-R-SMT(01)" prefix="J">
<description>&lt;b&gt;U.FL Series 6 Ghz 50 Ohm Ultra-small SMT Coaxial Cable Receptacle&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="U.FL-R-SMT(01)" x="0" y="0"/>
</gates>
<devices>
<device name="" package="HRS_U.FL-R-SMT(01)">
<connects>
<connect gate="G$1" pin="GND" pad="1 2"/>
<connect gate="G$1" pin="SIG" pad="3"/>
</connects>
<technologies>
<technology name="">
<attribute name="DESCRIPTION" value=" U.FL Series 6 Ghz 50 Ohm Ultra-small SMT Coaxial Cable Receptacle "/>
<attribute name="DIGI-KEY_PART_NUMBER" value="H9161-ND"/>
<attribute name="DIGI-KEY_PURCHASE_URL" value="https://www.digikey.ru/product-detail/en/hirose-electric-co-ltd/U.FL-R-SMT_01_/H9161-ND/513010?utm_source=snapeda&amp;utm_medium=aggregator&amp;utm_campaign=symbol"/>
<attribute name="MF" value="Hirose"/>
<attribute name="MP" value="U.FL-R-SMT_01_"/>
<attribute name="PACKAGE" value="None"/>
</technology>
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
<class number="0" name="RF" width="0.4" drill="0">
<clearance class="0" value="0.0645125"/>
</class>
</classes>
<parts>
<part name="U$1" library="iridium-antenna" deviceset="BY-IRIDIUM-254" device=""/>
<part name="J1" library="U.FL-R-SMT_01_" deviceset="U.FL-R-SMT(01)" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="63.5" y="63.5" smashed="yes">
<attribute name="NAME" x="66.04" y="60.96" size="1.27" layer="95"/>
</instance>
<instance part="J1" gate="G$1" x="93.98" y="50.8" smashed="yes">
<attribute name="NAME" x="90.16143125" y="54.87313125" size="1.27285" layer="95"/>
<attribute name="VALUE" x="89.65218125" y="45.1993" size="1.27288125" layer="96"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<pinref part="J1" gate="G$1" pin="SIG"/>
<pinref part="U$1" gate="G$1" pin="P$1"/>
<wire x1="83.82" y1="53.34" x2="63.5" y2="53.34" width="0.1524" layer="91"/>
<wire x1="63.5" y1="53.34" x2="63.5" y2="58.42" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
