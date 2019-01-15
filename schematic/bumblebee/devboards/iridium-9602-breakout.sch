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
<layer number="99" name="SpiceOrder" color="5" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="SAMTEC-CLP-110-02-X-D">
<packages>
<package name="SAMTEC-CLP-110-02-X-D">
<description>translated Allegro footprint</description>
<wire x1="-7.242" y1="-1.524" x2="-13.528" y2="-1.524" width="0" layer="150"/>
<wire x1="-12.827" y1="-0.318009375" x2="-12.827" y2="-1.524" width="0" layer="150"/>
<wire x1="-12.986" y1="-0.889" x2="-12.827" y2="-1.524" width="0" layer="150"/>
<wire x1="-12.827" y1="-1.524" x2="-12.668" y2="-0.889" width="0" layer="150"/>
<wire x1="-12.668" y1="-0.889" x2="-12.827" y2="-1.016" width="0" layer="150"/>
<wire x1="-12.827" y1="-1.016" x2="-12.986" y2="-0.889" width="0" layer="150"/>
<wire x1="-12.827" y1="-1.524" x2="-12.748" y2="-0.951990625" width="0" layer="150"/>
<wire x1="-12.748" y1="-0.951990625" x2="-12.827" y2="-1.016" width="0" layer="150"/>
<wire x1="-12.827" y1="-1.016" x2="-12.827" y2="-1.524" width="0" layer="150"/>
<wire x1="-12.827" y1="-1.524" x2="-12.906" y2="-0.951990625" width="0" layer="150"/>
<wire x1="-12.906" y1="-0.951990625" x2="-12.986" y2="-0.889" width="0" layer="150"/>
<wire x1="-7.242" y1="1.524" x2="-13.528" y2="1.524" width="0" layer="150"/>
<wire x1="-12.827" y1="0.318009375" x2="-12.827" y2="1.524" width="0" layer="150"/>
<wire x1="-12.668" y1="0.889" x2="-12.827" y2="1.524" width="0" layer="150"/>
<wire x1="-12.827" y1="1.524" x2="-12.986" y2="0.889" width="0" layer="150"/>
<wire x1="-12.986" y1="0.889" x2="-12.827" y2="1.016" width="0" layer="150"/>
<wire x1="-12.827" y1="1.016" x2="-12.668" y2="0.889" width="0" layer="150"/>
<wire x1="-12.827" y1="1.524" x2="-12.906" y2="0.951990625" width="0" layer="150"/>
<wire x1="-12.906" y1="0.951990625" x2="-12.827" y2="1.016" width="0" layer="150"/>
<wire x1="-12.827" y1="1.016" x2="-12.827" y2="1.524" width="0" layer="150"/>
<wire x1="-12.827" y1="1.524" x2="-12.748" y2="0.951990625" width="0" layer="150"/>
<wire x1="-12.748" y1="0.951990625" x2="-12.668" y2="0.889" width="0" layer="150"/>
<wire x1="-6.415990625" y1="-1.613" x2="-11.623" y2="-1.613" width="0" layer="150"/>
<wire x1="-10.922" y1="-0.318009375" x2="-10.922" y2="-1.613" width="0" layer="150"/>
<wire x1="-11.081" y1="-0.978003125" x2="-10.922" y2="-1.613" width="0" layer="150"/>
<wire x1="-10.922" y1="-1.613" x2="-10.763" y2="-0.978003125" width="0" layer="150"/>
<wire x1="-10.763" y1="-0.978003125" x2="-10.922" y2="-1.105" width="0" layer="150"/>
<wire x1="-10.922" y1="-1.105" x2="-11.081" y2="-0.978003125" width="0" layer="150"/>
<wire x1="-10.922" y1="-1.613" x2="-10.843" y2="-1.040990625" width="0" layer="150"/>
<wire x1="-10.843" y1="-1.040990625" x2="-10.922" y2="-1.105" width="0" layer="150"/>
<wire x1="-10.922" y1="-1.105" x2="-10.922" y2="-1.613" width="0" layer="150"/>
<wire x1="-10.922" y1="-1.613" x2="-11.001" y2="-1.040990625" width="0" layer="150"/>
<wire x1="-11.001" y1="-1.040990625" x2="-11.081" y2="-0.978003125" width="0" layer="150"/>
<wire x1="-6.415990625" y1="1.613" x2="-11.623" y2="1.613" width="0" layer="150"/>
<wire x1="-10.922" y1="0.318009375" x2="-10.922" y2="1.613" width="0" layer="150"/>
<wire x1="-10.763" y1="0.978003125" x2="-10.922" y2="1.613" width="0" layer="150"/>
<wire x1="-10.922" y1="1.613" x2="-11.081" y2="0.978003125" width="0" layer="150"/>
<wire x1="-11.081" y1="0.978003125" x2="-10.922" y2="1.105" width="0" layer="150"/>
<wire x1="-10.922" y1="1.105" x2="-10.763" y2="0.978003125" width="0" layer="150"/>
<wire x1="-10.922" y1="1.613" x2="-11.001" y2="1.040990625" width="0" layer="150"/>
<wire x1="-11.001" y1="1.040990625" x2="-10.922" y2="1.105" width="0" layer="150"/>
<wire x1="-10.922" y1="1.105" x2="-10.922" y2="1.613" width="0" layer="150"/>
<wire x1="-10.922" y1="1.613" x2="-10.843" y2="1.040990625" width="0" layer="150"/>
<wire x1="-10.843" y1="1.040990625" x2="-10.763" y2="0.978003125" width="0" layer="150"/>
<wire x1="-6.539990625" y1="-2.224990625" x2="-6.539990625" y2="-6.734" width="0" layer="150"/>
<wire x1="-6.833009375" y1="-3.874009375" x2="-5.715" y2="-3.874009375" width="0" layer="150"/>
<wire x1="-6.35" y1="-4.032" x2="-5.715" y2="-3.874009375" width="0" layer="150"/>
<wire x1="-5.715" y1="-3.874009375" x2="-6.35" y2="-3.715" width="0" layer="150"/>
<wire x1="-6.35" y1="-3.715" x2="-6.223" y2="-3.874009375" width="0" layer="150"/>
<wire x1="-6.223" y1="-3.874009375" x2="-6.35" y2="-4.032" width="0" layer="150"/>
<wire x1="-5.715" y1="-3.874009375" x2="-6.285990625" y2="-3.794" width="0" layer="150"/>
<wire x1="-6.285990625" y1="-3.794" x2="-6.223" y2="-3.874009375" width="0" layer="150"/>
<wire x1="-6.223" y1="-3.874009375" x2="-5.715" y2="-3.874009375" width="0" layer="150"/>
<wire x1="-5.715" y1="-3.874009375" x2="-6.285990625" y2="-3.953" width="0" layer="150"/>
<wire x1="-6.285990625" y1="-3.953" x2="-6.35" y2="-4.032" width="0" layer="150"/>
<wire x1="-0.99100625" y1="-6.031990625" x2="-6.539990625" y2="-6.031990625" width="0" layer="150"/>
<wire x1="-5.906009375" y1="-5.874" x2="-6.539990625" y2="-6.031990625" width="0" layer="150"/>
<wire x1="-6.539990625" y1="-6.031990625" x2="-5.906009375" y2="-6.191" width="0" layer="150"/>
<wire x1="-5.906009375" y1="-6.191" x2="-6.031990625" y2="-6.031990625" width="0" layer="150"/>
<wire x1="-6.031990625" y1="-6.031990625" x2="-5.906009375" y2="-5.874" width="0" layer="150"/>
<wire x1="-6.539990625" y1="-6.031990625" x2="-5.969" y2="-6.112" width="0" layer="150"/>
<wire x1="-5.969" y1="-6.112" x2="-6.031990625" y2="-6.031990625" width="0" layer="150"/>
<wire x1="-6.031990625" y1="-6.031990625" x2="-6.539990625" y2="-6.031990625" width="0" layer="150"/>
<wire x1="-6.539990625" y1="-6.031990625" x2="-5.969" y2="-5.953" width="0" layer="150"/>
<wire x1="-5.969" y1="-5.953" x2="-5.906009375" y2="-5.874" width="0" layer="150"/>
<polygon width="0" layer="39">
<vertex x="-6.615990625" y="-2.399"/>
<vertex x="-6.615990625" y="2.399"/>
<vertex x="6.615990625" y="2.399"/>
<vertex x="6.615990625" y="-2.399"/>
</polygon>
<wire x1="-6.566" y1="-1.524" x2="-5.08" y2="-1.524" width="0.1" layer="51"/>
<wire x1="-5.969" y1="-0.381" x2="-5.969" y2="-0.889" width="0.1" layer="51"/>
<wire x1="-5.969" y1="-0.889" x2="-5.461" y2="-0.889" width="0.1" layer="51"/>
<wire x1="-5.461" y1="-0.381" x2="-5.969" y2="-0.381" width="0.1" layer="51"/>
<wire x1="-6.566" y1="1.524" x2="-6.566" y2="-1.524" width="0.1" layer="51"/>
<wire x1="-5.512" y1="-2.159" x2="-5.918" y2="-2.159" width="0.1" layer="51"/>
<wire x1="-5.918" y1="-1.524" x2="-5.918" y2="-2.159" width="0.1" layer="51"/>
<wire x1="-7.015990625" y1="2.799" x2="-7.015990625" y2="-2.799" width="0.2" layer="21"/>
<wire x1="-7.015990625" y1="-2.799" x2="7.015990625" y2="-2.799" width="0.2" layer="21"/>
<wire x1="7.015990625" y1="-2.799" x2="7.015990625" y2="2.799" width="0.2" layer="21"/>
<wire x1="7.015990625" y1="2.799" x2="-7.015990625" y2="2.799" width="0.2" layer="21"/>
<wire x1="-5.08" y1="1.524" x2="-6.566" y2="1.524" width="0.1" layer="51"/>
<wire x1="-5.969" y1="0.889" x2="-5.969" y2="0.381" width="0.1" layer="51"/>
<wire x1="-5.969" y1="0.381" x2="-5.461" y2="0.381" width="0.1" layer="51"/>
<wire x1="-5.461" y1="0.889" x2="-5.969" y2="0.889" width="0.1" layer="51"/>
<wire x1="-5.918" y1="2.159" x2="-5.512" y2="2.159" width="0.1" layer="51"/>
<wire x1="-5.918" y1="1.524" x2="-5.918" y2="2.159" width="0.1" layer="51"/>
<wire x1="-5.715" y1="-2.313990625" x2="-5.715" y2="-4.575" width="0" layer="150"/>
<wire x1="-4.445" y1="-2.313990625" x2="-4.445" y2="-4.575" width="0" layer="150"/>
<wire x1="-3.175" y1="-3.874009375" x2="-4.445" y2="-3.874009375" width="0" layer="150"/>
<wire x1="-3.81" y1="-3.715" x2="-4.445" y2="-3.874009375" width="0" layer="150"/>
<wire x1="-4.445" y1="-3.874009375" x2="-3.81" y2="-4.032" width="0" layer="150"/>
<wire x1="-3.81" y1="-4.032" x2="-3.937" y2="-3.874009375" width="0" layer="150"/>
<wire x1="-3.937" y1="-3.874009375" x2="-3.81" y2="-3.715" width="0" layer="150"/>
<wire x1="-4.445" y1="-3.874009375" x2="-3.874009375" y2="-3.953" width="0" layer="150"/>
<wire x1="-3.874009375" y1="-3.953" x2="-3.937" y2="-3.874009375" width="0" layer="150"/>
<wire x1="-3.937" y1="-3.874009375" x2="-4.445" y2="-3.874009375" width="0" layer="150"/>
<wire x1="-4.445" y1="-3.874009375" x2="-3.874009375" y2="-3.794" width="0" layer="150"/>
<wire x1="-3.874009375" y1="-3.794" x2="-3.81" y2="-3.715" width="0" layer="150"/>
<wire x1="-5.715" y1="-2.313990625" x2="-5.715" y2="-5.591" width="0" layer="150"/>
<wire x1="-0.99100625" y1="-4.890009375" x2="-5.715" y2="-4.890009375" width="0" layer="150"/>
<wire x1="-5.08" y1="-4.731" x2="-5.715" y2="-4.890009375" width="0" layer="150"/>
<wire x1="-5.715" y1="-4.890009375" x2="-5.08" y2="-5.048" width="0" layer="150"/>
<wire x1="-5.08" y1="-5.048" x2="-5.207" y2="-4.890009375" width="0" layer="150"/>
<wire x1="-5.207" y1="-4.890009375" x2="-5.08" y2="-4.731" width="0" layer="150"/>
<wire x1="-5.715" y1="-4.890009375" x2="-5.144009375" y2="-4.969" width="0" layer="150"/>
<wire x1="-5.144009375" y1="-4.969" x2="-5.207" y2="-4.890009375" width="0" layer="150"/>
<wire x1="-5.207" y1="-4.890009375" x2="-5.715" y2="-4.890009375" width="0" layer="150"/>
<wire x1="-5.715" y1="-4.890009375" x2="-5.144009375" y2="-4.81" width="0" layer="150"/>
<wire x1="-5.144009375" y1="-4.81" x2="-5.08" y2="-4.731" width="0" layer="150"/>
<wire x1="-5.461" y1="-0.889" x2="-5.461" y2="-0.381" width="0.1" layer="51"/>
<wire x1="-5.512" y1="-1.524" x2="-5.512" y2="-2.159" width="0.1" layer="51"/>
<wire x1="-5.08" y1="-1.524" x2="-3.81" y2="-1.524" width="0.1" layer="51"/>
<wire x1="-4.648" y1="-2.159" x2="-4.648" y2="-1.524" width="0.1" layer="51"/>
<wire x1="-4.242" y1="-1.524" x2="-4.242" y2="-2.159" width="0.1" layer="51"/>
<wire x1="-4.242" y1="-2.159" x2="-4.648" y2="-2.159" width="0.1" layer="51"/>
<wire x1="-4.191" y1="-0.381" x2="-4.699" y2="-0.381" width="0.1" layer="51"/>
<wire x1="-4.191" y1="-0.889" x2="-4.191" y2="-0.381" width="0.1" layer="51"/>
<wire x1="-4.699" y1="-0.889" x2="-4.191" y2="-0.889" width="0.1" layer="51"/>
<wire x1="-4.699" y1="-0.381" x2="-4.699" y2="-0.889" width="0.1" layer="51"/>
<wire x1="-3.81" y1="-1.524" x2="-2.54" y2="-1.524" width="0.1" layer="51"/>
<wire x1="-3.378" y1="-2.159" x2="-3.378" y2="-1.524" width="0.1" layer="51"/>
<wire x1="-2.972" y1="-1.524" x2="-2.972" y2="-2.159" width="0.1" layer="51"/>
<wire x1="-2.972" y1="-2.159" x2="-3.378" y2="-2.159" width="0.1" layer="51"/>
<wire x1="-2.921" y1="-0.381" x2="-3.429" y2="-0.381" width="0.1" layer="51"/>
<wire x1="-2.921" y1="-0.889" x2="-2.921" y2="-0.381" width="0.1" layer="51"/>
<wire x1="-3.429" y1="-0.889" x2="-2.921" y2="-0.889" width="0.1" layer="51"/>
<wire x1="-3.429" y1="-0.381" x2="-3.429" y2="-0.889" width="0.1" layer="51"/>
<wire x1="-2.54" y1="-1.524" x2="-1.27" y2="-1.524" width="0.1" layer="51"/>
<wire x1="-5.461" y1="0.381" x2="-5.461" y2="0.889" width="0.1" layer="51"/>
<wire x1="-5.512" y1="2.159" x2="-5.512" y2="1.524" width="0.1" layer="51"/>
<wire x1="-3.81" y1="1.524" x2="-5.08" y2="1.524" width="0.1" layer="51"/>
<wire x1="-4.242" y1="2.159" x2="-4.242" y2="1.524" width="0.1" layer="51"/>
<wire x1="-4.648" y1="1.524" x2="-4.648" y2="2.159" width="0.1" layer="51"/>
<wire x1="-4.648" y1="2.159" x2="-4.242" y2="2.159" width="0.1" layer="51"/>
<wire x1="-4.191" y1="0.889" x2="-4.699" y2="0.889" width="0.1" layer="51"/>
<wire x1="-4.191" y1="0.381" x2="-4.191" y2="0.889" width="0.1" layer="51"/>
<wire x1="-4.699" y1="0.381" x2="-4.191" y2="0.381" width="0.1" layer="51"/>
<wire x1="-4.699" y1="0.889" x2="-4.699" y2="0.381" width="0.1" layer="51"/>
<wire x1="-2.54" y1="1.524" x2="-3.81" y2="1.524" width="0.1" layer="51"/>
<wire x1="-2.972" y1="2.159" x2="-2.972" y2="1.524" width="0.1" layer="51"/>
<wire x1="-3.378" y1="1.524" x2="-3.378" y2="2.159" width="0.1" layer="51"/>
<wire x1="-3.378" y1="2.159" x2="-2.972" y2="2.159" width="0.1" layer="51"/>
<wire x1="-2.921" y1="0.889" x2="-3.429" y2="0.889" width="0.1" layer="51"/>
<wire x1="-2.921" y1="0.381" x2="-2.921" y2="0.889" width="0.1" layer="51"/>
<wire x1="-3.429" y1="0.381" x2="-2.921" y2="0.381" width="0.1" layer="51"/>
<wire x1="-3.429" y1="0.889" x2="-3.429" y2="0.381" width="0.1" layer="51"/>
<wire x1="-1.27" y1="1.524" x2="-2.54" y2="1.524" width="0.1" layer="51"/>
<wire x1="-2.108" y1="-2.159" x2="-2.108" y2="-1.524" width="0.1" layer="51"/>
<wire x1="-1.702" y1="-1.524" x2="-1.702" y2="-2.159" width="0.1" layer="51"/>
<wire x1="-1.702" y1="-2.159" x2="-2.108" y2="-2.159" width="0.1" layer="51"/>
<wire x1="-1.651" y1="-0.381" x2="-2.159" y2="-0.381" width="0.1" layer="51"/>
<wire x1="-1.651" y1="-0.889" x2="-1.651" y2="-0.381" width="0.1" layer="51"/>
<wire x1="-2.159" y1="-0.889" x2="-1.651" y2="-0.889" width="0.1" layer="51"/>
<wire x1="-2.159" y1="-0.381" x2="-2.159" y2="-0.889" width="0.1" layer="51"/>
<wire x1="-1.27" y1="-1.524" x2="0" y2="-1.524" width="0.1" layer="51"/>
<wire x1="-0.837996875" y1="-2.159" x2="-0.837996875" y2="-1.524" width="0.1" layer="51"/>
<wire x1="-0.432003125" y1="-1.524" x2="-0.432003125" y2="-2.159" width="0.1" layer="51"/>
<wire x1="-0.432003125" y1="-2.159" x2="-0.837996875" y2="-2.159" width="0.1" layer="51"/>
<wire x1="-0.381" y1="-0.381" x2="-0.889" y2="-0.381" width="0.1" layer="51"/>
<wire x1="-0.381" y1="-0.889" x2="-0.381" y2="-0.381" width="0.1" layer="51"/>
<wire x1="-0.889" y1="-0.889" x2="-0.381" y2="-0.889" width="0.1" layer="51"/>
<wire x1="-0.889" y1="-0.381" x2="-0.889" y2="-0.889" width="0.1" layer="51"/>
<wire x1="0" y1="-1.524" x2="1.27" y2="-1.524" width="0.1" layer="51"/>
<wire x1="0.432003125" y1="-2.159" x2="0.432003125" y2="-1.524" width="0.1" layer="51"/>
<wire x1="0.837996875" y1="-1.524" x2="0.837996875" y2="-2.159" width="0.1" layer="51"/>
<wire x1="0.837996875" y1="-2.159" x2="0.432003125" y2="-2.159" width="0.1" layer="51"/>
<wire x1="0.889" y1="-0.381" x2="0.381" y2="-0.381" width="0.1" layer="51"/>
<wire x1="0.889" y1="-0.889" x2="0.889" y2="-0.381" width="0.1" layer="51"/>
<wire x1="0.381" y1="-0.889" x2="0.889" y2="-0.889" width="0.1" layer="51"/>
<wire x1="0.381" y1="-0.381" x2="0.381" y2="-0.889" width="0.1" layer="51"/>
<wire x1="-1.702" y1="2.159" x2="-1.702" y2="1.524" width="0.1" layer="51"/>
<wire x1="-2.108" y1="1.524" x2="-2.108" y2="2.159" width="0.1" layer="51"/>
<wire x1="-2.108" y1="2.159" x2="-1.702" y2="2.159" width="0.1" layer="51"/>
<wire x1="-1.651" y1="0.889" x2="-2.159" y2="0.889" width="0.1" layer="51"/>
<wire x1="-1.651" y1="0.381" x2="-1.651" y2="0.889" width="0.1" layer="51"/>
<wire x1="-2.159" y1="0.381" x2="-1.651" y2="0.381" width="0.1" layer="51"/>
<wire x1="-2.159" y1="0.889" x2="-2.159" y2="0.381" width="0.1" layer="51"/>
<wire x1="0" y1="1.524" x2="-1.27" y2="1.524" width="0.1" layer="51"/>
<wire x1="-0.432003125" y1="2.159" x2="-0.432003125" y2="1.524" width="0.1" layer="51"/>
<wire x1="-0.837996875" y1="1.524" x2="-0.837996875" y2="2.159" width="0.1" layer="51"/>
<wire x1="-0.837996875" y1="2.159" x2="-0.432003125" y2="2.159" width="0.1" layer="51"/>
<wire x1="-0.381" y1="0.889" x2="-0.889" y2="0.889" width="0.1" layer="51"/>
<wire x1="-0.381" y1="0.381" x2="-0.381" y2="0.889" width="0.1" layer="51"/>
<wire x1="-0.889" y1="0.381" x2="-0.381" y2="0.381" width="0.1" layer="51"/>
<wire x1="-0.889" y1="0.889" x2="-0.889" y2="0.381" width="0.1" layer="51"/>
<wire x1="1.27" y1="1.524" x2="0" y2="1.524" width="0.1" layer="51"/>
<wire x1="0.837996875" y1="2.159" x2="0.837996875" y2="1.524" width="0.1" layer="51"/>
<wire x1="0.432003125" y1="1.524" x2="0.432003125" y2="2.159" width="0.1" layer="51"/>
<wire x1="0.432003125" y1="2.159" x2="0.837996875" y2="2.159" width="0.1" layer="51"/>
<wire x1="0.889" y1="0.889" x2="0.381" y2="0.889" width="0.1" layer="51"/>
<wire x1="0.889" y1="0.381" x2="0.889" y2="0.889" width="0.1" layer="51"/>
<wire x1="0.381" y1="0.381" x2="0.889" y2="0.381" width="0.1" layer="51"/>
<wire x1="0.381" y1="0.889" x2="0.381" y2="0.381" width="0.1" layer="51"/>
<wire x1="0.99100625" y1="-4.890009375" x2="5.715" y2="-4.890009375" width="0" layer="150"/>
<wire x1="0.99100625" y1="-6.031990625" x2="6.539990625" y2="-6.031990625" width="0" layer="150"/>
<wire x1="1.27" y1="-1.524" x2="2.54" y2="-1.524" width="0.1" layer="51"/>
<wire x1="1.702" y1="-2.159" x2="1.702" y2="-1.524" width="0.1" layer="51"/>
<wire x1="2.108" y1="-1.524" x2="2.108" y2="-2.159" width="0.1" layer="51"/>
<wire x1="2.108" y1="-2.159" x2="1.702" y2="-2.159" width="0.1" layer="51"/>
<wire x1="2.159" y1="-0.381" x2="1.651" y2="-0.381" width="0.1" layer="51"/>
<wire x1="2.159" y1="-0.889" x2="2.159" y2="-0.381" width="0.1" layer="51"/>
<wire x1="1.651" y1="-0.889" x2="2.159" y2="-0.889" width="0.1" layer="51"/>
<wire x1="1.651" y1="-0.381" x2="1.651" y2="-0.889" width="0.1" layer="51"/>
<wire x1="2.54" y1="-1.524" x2="3.81" y2="-1.524" width="0.1" layer="51"/>
<wire x1="2.972" y1="-2.159" x2="2.972" y2="-1.524" width="0.1" layer="51"/>
<wire x1="3.378" y1="-1.524" x2="3.378" y2="-2.159" width="0.1" layer="51"/>
<wire x1="3.378" y1="-2.159" x2="2.972" y2="-2.159" width="0.1" layer="51"/>
<wire x1="3.429" y1="-0.381" x2="2.921" y2="-0.381" width="0.1" layer="51"/>
<wire x1="3.429" y1="-0.889" x2="3.429" y2="-0.381" width="0.1" layer="51"/>
<wire x1="2.921" y1="-0.889" x2="3.429" y2="-0.889" width="0.1" layer="51"/>
<wire x1="2.921" y1="-0.381" x2="2.921" y2="-0.889" width="0.1" layer="51"/>
<wire x1="3.81" y1="-1.524" x2="5.08" y2="-1.524" width="0.1" layer="51"/>
<wire x1="4.242" y1="-2.159" x2="4.242" y2="-1.524" width="0.1" layer="51"/>
<wire x1="4.648" y1="-2.159" x2="4.242" y2="-2.159" width="0.1" layer="51"/>
<wire x1="4.699" y1="-0.381" x2="4.191" y2="-0.381" width="0.1" layer="51"/>
<wire x1="4.191" y1="-0.889" x2="4.699" y2="-0.889" width="0.1" layer="51"/>
<wire x1="4.191" y1="-0.381" x2="4.191" y2="-0.889" width="0.1" layer="51"/>
<wire x1="2.54" y1="1.524" x2="1.27" y2="1.524" width="0.1" layer="51"/>
<wire x1="2.108" y1="2.159" x2="2.108" y2="1.524" width="0.1" layer="51"/>
<wire x1="1.702" y1="1.524" x2="1.702" y2="2.159" width="0.1" layer="51"/>
<wire x1="1.702" y1="2.159" x2="2.108" y2="2.159" width="0.1" layer="51"/>
<wire x1="2.159" y1="0.889" x2="1.651" y2="0.889" width="0.1" layer="51"/>
<wire x1="2.159" y1="0.381" x2="2.159" y2="0.889" width="0.1" layer="51"/>
<wire x1="1.651" y1="0.381" x2="2.159" y2="0.381" width="0.1" layer="51"/>
<wire x1="1.651" y1="0.889" x2="1.651" y2="0.381" width="0.1" layer="51"/>
<wire x1="3.81" y1="1.524" x2="2.54" y2="1.524" width="0.1" layer="51"/>
<wire x1="3.378" y1="2.159" x2="3.378" y2="1.524" width="0.1" layer="51"/>
<wire x1="2.972" y1="1.524" x2="2.972" y2="2.159" width="0.1" layer="51"/>
<wire x1="2.972" y1="2.159" x2="3.378" y2="2.159" width="0.1" layer="51"/>
<wire x1="3.429" y1="0.889" x2="2.921" y2="0.889" width="0.1" layer="51"/>
<wire x1="3.429" y1="0.381" x2="3.429" y2="0.889" width="0.1" layer="51"/>
<wire x1="2.921" y1="0.381" x2="3.429" y2="0.381" width="0.1" layer="51"/>
<wire x1="2.921" y1="0.889" x2="2.921" y2="0.381" width="0.1" layer="51"/>
<wire x1="5.08" y1="1.524" x2="3.81" y2="1.524" width="0.1" layer="51"/>
<wire x1="4.242" y1="1.524" x2="4.242" y2="2.159" width="0.1" layer="51"/>
<wire x1="4.242" y1="2.159" x2="4.648" y2="2.159" width="0.1" layer="51"/>
<wire x1="4.699" y1="0.889" x2="4.191" y2="0.889" width="0.1" layer="51"/>
<wire x1="4.191" y1="0.381" x2="4.699" y2="0.381" width="0.1" layer="51"/>
<wire x1="4.191" y1="0.889" x2="4.191" y2="0.381" width="0.1" layer="51"/>
<wire x1="6.539990625" y1="-2.224990625" x2="6.539990625" y2="-6.734" width="0" layer="150"/>
<wire x1="5.715" y1="-2.313990625" x2="5.715" y2="-5.591" width="0" layer="150"/>
<wire x1="5.08" y1="-5.048" x2="5.715" y2="-4.890009375" width="0" layer="150"/>
<wire x1="5.715" y1="-4.890009375" x2="5.08" y2="-4.731" width="0" layer="150"/>
<wire x1="5.08" y1="-4.731" x2="5.207" y2="-4.890009375" width="0" layer="150"/>
<wire x1="5.207" y1="-4.890009375" x2="5.08" y2="-5.048" width="0" layer="150"/>
<wire x1="5.715" y1="-4.890009375" x2="5.144009375" y2="-4.81" width="0" layer="150"/>
<wire x1="5.144009375" y1="-4.81" x2="5.207" y2="-4.890009375" width="0" layer="150"/>
<wire x1="5.207" y1="-4.890009375" x2="5.715" y2="-4.890009375" width="0" layer="150"/>
<wire x1="5.715" y1="-4.890009375" x2="5.144009375" y2="-4.969" width="0" layer="150"/>
<wire x1="5.144009375" y1="-4.969" x2="5.08" y2="-5.048" width="0" layer="150"/>
<wire x1="5.906009375" y1="-6.191" x2="6.539990625" y2="-6.031990625" width="0" layer="150"/>
<wire x1="6.539990625" y1="-6.031990625" x2="5.906009375" y2="-5.874" width="0" layer="150"/>
<wire x1="5.906009375" y1="-5.874" x2="6.031990625" y2="-6.031990625" width="0" layer="150"/>
<wire x1="6.031990625" y1="-6.031990625" x2="5.906009375" y2="-6.191" width="0" layer="150"/>
<wire x1="6.539990625" y1="-6.031990625" x2="5.969" y2="-5.953" width="0" layer="150"/>
<wire x1="5.969" y1="-5.953" x2="6.031990625" y2="-6.031990625" width="0" layer="150"/>
<wire x1="6.031990625" y1="-6.031990625" x2="6.539990625" y2="-6.031990625" width="0" layer="150"/>
<wire x1="6.539990625" y1="-6.031990625" x2="5.969" y2="-6.112" width="0" layer="150"/>
<wire x1="5.969" y1="-6.112" x2="5.906009375" y2="-6.191" width="0" layer="150"/>
<wire x1="4.648" y1="-1.524" x2="4.648" y2="-2.159" width="0.1" layer="51"/>
<wire x1="4.699" y1="-0.889" x2="4.699" y2="-0.381" width="0.1" layer="51"/>
<wire x1="5.08" y1="-1.524" x2="6.566" y2="-1.524" width="0.1" layer="51"/>
<wire x1="5.918" y1="-2.159" x2="5.512" y2="-2.159" width="0.1" layer="51"/>
<wire x1="6.566" y1="-1.524" x2="6.566" y2="1.524" width="0.1" layer="51"/>
<wire x1="5.461" y1="-0.381" x2="5.461" y2="-0.889" width="0.1" layer="51"/>
<wire x1="5.461" y1="-0.889" x2="5.969" y2="-0.889" width="0.1" layer="51"/>
<wire x1="5.969" y1="-0.889" x2="5.969" y2="-0.381" width="0.1" layer="51"/>
<wire x1="5.969" y1="-0.381" x2="5.461" y2="-0.381" width="0.1" layer="51"/>
<wire x1="5.512" y1="-2.159" x2="5.512" y2="-1.524" width="0.1" layer="51"/>
<wire x1="5.918" y1="-1.524" x2="5.918" y2="-2.159" width="0.1" layer="51"/>
<wire x1="4.648" y1="2.159" x2="4.648" y2="1.524" width="0.1" layer="51"/>
<wire x1="4.699" y1="0.381" x2="4.699" y2="0.889" width="0.1" layer="51"/>
<wire x1="6.566" y1="1.524" x2="5.08" y2="1.524" width="0.1" layer="51"/>
<wire x1="5.461" y1="0.889" x2="5.461" y2="0.381" width="0.1" layer="51"/>
<wire x1="5.461" y1="0.381" x2="5.969" y2="0.381" width="0.1" layer="51"/>
<wire x1="5.969" y1="0.381" x2="5.969" y2="0.889" width="0.1" layer="51"/>
<wire x1="5.969" y1="0.889" x2="5.461" y2="0.889" width="0.1" layer="51"/>
<wire x1="5.512" y1="2.159" x2="5.918" y2="2.159" width="0.1" layer="51"/>
<wire x1="5.512" y1="1.524" x2="5.512" y2="2.159" width="0.1" layer="51"/>
<wire x1="5.918" y1="1.524" x2="5.918" y2="2.159" width="0.1" layer="51"/>
<text x="-13.4916" y="-0.12704375" size="0.2540875" layer="150">3.048</text>
<text x="-11.5987" y="-0.127184375" size="0.254365625" layer="150">3.226</text>
<text x="-8.35648125" y="-4.00596875" size="0.25438125" layer="150">1.270</text>
<text x="-8.39245" y="-2.24973125" size="1.27098125" layer="21">2</text>
<text x="-8.388059375" y="-2.248559375" size="1.270309375" layer="51">2</text>
<text x="-8.396359375" y="0.9792125" size="1.27156875" layer="21">1</text>
<text x="-8.4005" y="0.97969375" size="1.2722" layer="51">1</text>
<text x="-0.800284375" y="-5.01778125" size="0.254090625" layer="150">11.430</text>
<text x="-0.801553125" y="-6.17196875" size="0.25449375" layer="150">13.081</text>
<text x="7.3603" y="-2.249009375" size="1.27056875" layer="21">20</text>
<text x="7.357009375" y="-2.248" size="1.27" layer="51">20</text>
<text x="7.362459375" y="0.978728125" size="1.270940625" layer="21">19</text>
<text x="7.362159375" y="0.9786875" size="1.270890625" layer="51">19</text>
<text x="-7.1169" y="3.534459375" size="1.905240625" layer="25" align="bottom-right">&gt;NAME</text>
<text x="0" y="-0.700453125" size="0.6354125" layer="27" align="bottom-center">&gt;VALUE</text>
<rectangle x1="-6.13948125" y1="0.827465625" x2="-5.294" y2="2.399" layer="29"/>
<rectangle x1="-6.08516875" y1="0.878028125" x2="-5.345" y2="2.348" layer="31"/>
<rectangle x1="-6.14366875" y1="-2.402" x2="-5.294" y2="-0.827" layer="29"/>
<rectangle x1="-6.09431875" y1="-2.3516" x2="-5.345" y2="-0.878003125" layer="31"/>
<rectangle x1="-4.874059375" y1="0.82836875" x2="-4.024" y2="2.399" layer="29"/>
<rectangle x1="-4.822890625" y1="0.879440625" x2="-4.075" y2="2.348" layer="31"/>
<rectangle x1="-4.872509375" y1="-2.402209375" x2="-4.024" y2="-0.827" layer="29"/>
<rectangle x1="-4.82076875" y1="-2.350809375" x2="-4.075" y2="-0.878003125" layer="31"/>
<rectangle x1="-3.60068125" y1="0.828075" x2="-2.754" y2="2.399" layer="29"/>
<rectangle x1="-3.545909375" y1="0.878228125" x2="-2.805" y2="2.348" layer="31"/>
<rectangle x1="-3.59796875" y1="-2.400309375" x2="-2.754" y2="-0.827" layer="29"/>
<rectangle x1="-3.54721875" y1="-2.34946875" x2="-2.805" y2="-0.878003125" layer="31"/>
<rectangle x1="-2.33001875" y1="0.828428125" x2="-1.484" y2="2.399" layer="29"/>
<rectangle x1="-2.279459375" y1="0.879721875" x2="-1.535" y2="2.348" layer="31"/>
<rectangle x1="-2.328090625" y1="-2.401159375" x2="-1.483990625" y2="-0.827" layer="29"/>
<rectangle x1="-2.279409375" y1="-2.35255" x2="-1.535" y2="-0.878003125" layer="31"/>
<rectangle x1="-1.057790625" y1="0.82839375" x2="-0.21399375" y2="2.399" layer="29"/>
<rectangle x1="-1.00663125" y1="0.879425" x2="-0.264996875" y2="2.348" layer="31"/>
<rectangle x1="-1.05718125" y1="-2.40166875" x2="-0.21399375" y2="-0.827" layer="29"/>
<rectangle x1="-1.00688125" y1="-2.352390625" x2="-0.264996875" y2="-0.878003125" layer="31"/>
<rectangle x1="0.214275" y1="0.828075" x2="1.056009375" y2="2.399" layer="29"/>
<rectangle x1="0.2652625" y1="0.87888125" x2="1.005" y2="2.348" layer="31"/>
<rectangle x1="0.214359375" y1="-2.40308125" x2="1.056009375" y2="-0.827" layer="29"/>
<rectangle x1="0.265390625" y1="-2.351490625" x2="1.005" y2="-0.878003125" layer="31"/>
<rectangle x1="1.486" y1="0.82811875" x2="2.326" y2="2.399" layer="29"/>
<rectangle x1="1.5369" y1="0.879090625" x2="2.275" y2="2.348" layer="31"/>
<rectangle x1="1.485159375" y1="-2.40088125" x2="2.326" y2="-0.827" layer="29"/>
<rectangle x1="1.53775" y1="-2.352209375" x2="2.275" y2="-0.878003125" layer="31"/>
<rectangle x1="2.75448125" y1="0.82714375" x2="3.596" y2="2.399" layer="29"/>
<rectangle x1="2.810309375" y1="0.8796625" x2="3.545" y2="2.348" layer="31"/>
<rectangle x1="2.75671875" y1="-2.40138125" x2="3.596" y2="-0.827" layer="29"/>
<rectangle x1="2.80653125" y1="-2.34928125" x2="3.545" y2="-0.878003125" layer="31"/>
<rectangle x1="4.031090625" y1="0.828459375" x2="4.866" y2="2.399" layer="29"/>
<rectangle x1="4.08208125" y1="0.879528125" x2="4.815" y2="2.348" layer="31"/>
<rectangle x1="4.027690625" y1="-2.401209375" x2="4.866" y2="-0.827" layer="29"/>
<rectangle x1="4.07976875" y1="-2.35075" x2="4.815" y2="-0.878003125" layer="31"/>
<rectangle x1="5.29778125" y1="0.827590625" x2="6.136009375" y2="2.399" layer="29"/>
<rectangle x1="5.34905" y1="0.878665625" x2="6.085" y2="2.348" layer="31"/>
<rectangle x1="5.30311875" y1="-2.403140625" x2="6.136" y2="-0.827" layer="29"/>
<rectangle x1="5.354040625" y1="-2.35196875" x2="6.085" y2="-0.878003125" layer="31"/>
<smd name="1" x="-5.715" y="1.613" dx="0.740003125" dy="1.47" layer="1" stop="no"/>
<smd name="2" x="-5.715" y="-1.613" dx="0.740003125" dy="1.47" layer="1" stop="no"/>
<smd name="3" x="-4.445" y="1.613" dx="0.740003125" dy="1.47" layer="1" stop="no"/>
<smd name="4" x="-4.445" y="-1.613" dx="0.740003125" dy="1.47" layer="1" stop="no"/>
<smd name="5" x="-3.175" y="1.613" dx="0.740003125" dy="1.47" layer="1" stop="no"/>
<smd name="6" x="-3.175" y="-1.613" dx="0.740003125" dy="1.47" layer="1" stop="no"/>
<smd name="7" x="-1.905" y="1.613" dx="0.740003125" dy="1.47" layer="1" stop="no"/>
<smd name="8" x="-1.905" y="-1.613" dx="0.740003125" dy="1.47" layer="1" stop="no"/>
<smd name="9" x="-0.635" y="1.613" dx="0.740003125" dy="1.47" layer="1" stop="no"/>
<smd name="10" x="-0.635" y="-1.613" dx="0.740003125" dy="1.47" layer="1" stop="no"/>
<smd name="11" x="0.635" y="1.613" dx="0.740003125" dy="1.47" layer="1" stop="no"/>
<smd name="12" x="0.635" y="-1.613" dx="0.740003125" dy="1.47" layer="1" stop="no"/>
<smd name="13" x="1.905" y="1.613" dx="0.740003125" dy="1.47" layer="1" stop="no"/>
<smd name="14" x="1.905" y="-1.613" dx="0.740003125" dy="1.47" layer="1" stop="no"/>
<smd name="15" x="3.175" y="1.613" dx="0.740003125" dy="1.47" layer="1" stop="no"/>
<smd name="16" x="3.175" y="-1.613" dx="0.740003125" dy="1.47" layer="1" stop="no"/>
<smd name="17" x="4.445" y="1.613" dx="0.740003125" dy="1.47" layer="1" stop="no"/>
<smd name="18" x="4.445" y="-1.613" dx="0.740003125" dy="1.47" layer="1" stop="no"/>
<smd name="19" x="5.715" y="1.613" dx="0.740003125" dy="1.47" layer="1" stop="no"/>
<smd name="20" x="5.715" y="-1.613" dx="0.740003125" dy="1.47" layer="1" stop="no"/>
</package>
</packages>
<symbols>
<symbol name="SAMTEC-CLP-110-02-X-DA">
<text x="0" y="5.088490625" size="2.544240625" layer="95">&gt;NAME</text>
<wire x1="0" y1="5.08" x2="20.3" y2="5.08" width="0.254" layer="94"/>
<wire x1="20.3" y1="5.08" x2="20.3" y2="-27.94" width="0.254" layer="94"/>
<wire x1="20.3" y1="-27.94" x2="0" y2="-27.94" width="0.254" layer="94"/>
<wire x1="0" y1="-27.94" x2="0" y2="5.08" width="0.254" layer="94"/>
<text x="0" y="-30.5279" size="2.289590625" layer="96">&gt;PARTNO</text>
<text x="0" y="-33.0813" size="2.290240625" layer="96">&gt;VALUE</text>
<text x="0" y="-35.5635" size="2.28623125" layer="94">SAMTEC-CLP-110-02-X-D</text>
<pin name="1" x="-5.08" y="0" length="middle" direction="pas"/>
<pin name="2" x="25.4" y="0" length="middle" direction="pas" rot="R180"/>
<pin name="3" x="-5.08" y="-2.54" length="middle" direction="pas"/>
<pin name="4" x="25.4" y="-2.54" length="middle" direction="pas" rot="R180"/>
<pin name="5" x="-5.08" y="-5.08" length="middle" direction="pas"/>
<pin name="6" x="25.4" y="-5.08" length="middle" direction="pas" rot="R180"/>
<pin name="7" x="-5.08" y="-7.62" length="middle" direction="pas"/>
<pin name="8" x="25.4" y="-7.62" length="middle" direction="pas" rot="R180"/>
<pin name="9" x="-5.08" y="-10.16" length="middle" direction="pas"/>
<pin name="10" x="25.4" y="-10.16" length="middle" direction="pas" rot="R180"/>
<pin name="11" x="-5.08" y="-12.7" length="middle" direction="pas"/>
<pin name="12" x="25.4" y="-12.7" length="middle" direction="pas" rot="R180"/>
<pin name="13" x="-5.08" y="-15.24" length="middle" direction="pas"/>
<pin name="14" x="25.4" y="-15.24" length="middle" direction="pas" rot="R180"/>
<pin name="15" x="-5.08" y="-17.78" length="middle" direction="pas"/>
<pin name="16" x="25.4" y="-17.78" length="middle" direction="pas" rot="R180"/>
<pin name="17" x="-5.08" y="-20.32" length="middle" direction="pas"/>
<pin name="18" x="25.4" y="-20.32" length="middle" direction="pas" rot="R180"/>
<pin name="19" x="-5.08" y="-22.86" length="middle" direction="pas"/>
<pin name="20" x="25.4" y="-22.86" length="middle" direction="pas" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="SAMTEC-CLP-110-02-X-D">
<gates>
<gate name="A" symbol="SAMTEC-CLP-110-02-X-DA" x="0" y="0"/>
</gates>
<devices>
<device name="J" package="SAMTEC-CLP-110-02-X-D">
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
<technologies>
<technology name="">
<attribute name="DESCRIPTION" value=" .050 Tiger Claw™ Rugged Reliable Dual Wipe Socket Strip "/>
<attribute name="DIGI-KEY_PART_NUMBER" value="CLP-110-02-L-D-K-ND"/>
<attribute name="DIGI-KEY_PURCHASE_URL" value="https://www.digikey.ru/product-detail/en/samtec-inc/CLP-110-02-L-D-K/CLP-110-02-L-D-K-ND/6693709?utm_source=snapeda&amp;utm_medium=aggregator&amp;utm_campaign=symbol"/>
<attribute name="MF" value="Samtec Inc."/>
<attribute name="MP" value="CLP-110-02-L-D-K"/>
<attribute name="PACKAGE" value="None"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="MMCX-P-P-X-ST-TH1">
<packages>
<package name="MMCX-P-P-X-ST-TH1">
<description>MMCX STRAIGHT,THROUGH HOLE PLUG - 50 OHM.</description>
<wire x1="-1.75" y1="1.41" x2="-1.41" y2="1.75" width="0.127" layer="51"/>
<wire x1="-1.41" y1="1.75" x2="1.41" y2="1.75" width="0.127" layer="51"/>
<wire x1="1.41" y1="1.75" x2="1.75" y2="1.41" width="0.127" layer="51"/>
<wire x1="1.75" y1="1.41" x2="1.75" y2="-1.41" width="0.127" layer="51"/>
<wire x1="1.75" y1="-1.41" x2="1.41" y2="-1.75" width="0.127" layer="51"/>
<wire x1="1.41" y1="-1.75" x2="-1.41" y2="-1.75" width="0.127" layer="51"/>
<wire x1="-1.41" y1="-1.75" x2="-1.75" y2="-1.41" width="0.127" layer="51"/>
<wire x1="-1.75" y1="-1.41" x2="-1.75" y2="1.41" width="0.127" layer="51"/>
<wire x1="-2.3" y1="1.7" x2="-1.7" y2="2.3" width="0.127" layer="21"/>
<wire x1="-1.7" y1="2.3" x2="1.7" y2="2.3" width="0.127" layer="21"/>
<wire x1="1.7" y1="2.3" x2="2.3" y2="1.7" width="0.127" layer="21"/>
<wire x1="2.3" y1="1.7" x2="2.3" y2="-1.7" width="0.127" layer="21"/>
<wire x1="2.3" y1="-1.7" x2="1.7" y2="-2.3" width="0.127" layer="21"/>
<wire x1="1.7" y1="-2.3" x2="-1.7" y2="-2.3" width="0.127" layer="21"/>
<wire x1="-1.7" y1="-2.3" x2="-2.3" y2="-1.7" width="0.127" layer="21"/>
<wire x1="-2.3" y1="-1.7" x2="-2.3" y2="1.7" width="0.127" layer="21"/>
<text x="-2.54423125" y="2.54423125" size="1.272109375" layer="25">&gt;NAME</text>
<text x="-2.54041875" y="-3.810640625" size="1.270209375" layer="27">&gt;VALUE</text>
<pad name="1" x="0" y="0" drill="0.84" diameter="1.3"/>
<pad name="4" x="1.27" y="1.27" drill="0.84" diameter="1.3"/>
<pad name="2" x="-1.27" y="1.27" drill="0.84" diameter="1.3"/>
<pad name="5" x="1.27" y="-1.27" drill="0.84" diameter="1.3"/>
<pad name="3" x="-1.27" y="-1.27" drill="0.84" diameter="1.3"/>
</package>
</packages>
<symbols>
<symbol name="MMCX-P-P-X-ST-TH1">
<wire x1="-5.08" y1="6.35" x2="5.08" y2="6.35" width="0.254" layer="94"/>
<wire x1="5.08" y1="6.35" x2="5.08" y2="-6.35" width="0.254" layer="94"/>
<wire x1="5.08" y1="-6.35" x2="-5.08" y2="-6.35" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-6.35" x2="-5.08" y2="6.35" width="0.254" layer="94"/>
<text x="-5.08675" y="7.63011875" size="1.271690625" layer="95">&gt;NAME</text>
<text x="-5.08753125" y="-8.903190625" size="1.27188125" layer="96">&gt;VALUE</text>
<pin name="1" x="-10.16" y="3.81" visible="pad" length="middle" direction="nc"/>
<pin name="GND@1" x="-10.16" y="-1.27" length="middle" direction="pwr"/>
<pin name="GND@2" x="10.16" y="-1.27" length="middle" direction="pwr" rot="R180"/>
<pin name="GND@3" x="-10.16" y="-3.81" length="middle" direction="pwr"/>
<pin name="GND@4" x="10.16" y="-3.81" length="middle" direction="pwr" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="MMCX-P-P-X-ST-TH1" prefix="J">
<description>MMCX STRAIGHT,THROUGH HOLE PLUG - 50 OHM.</description>
<gates>
<gate name="G$1" symbol="MMCX-P-P-X-ST-TH1" x="0" y="0"/>
</gates>
<devices>
<device name="" package="MMCX-P-P-X-ST-TH1">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="GND@1" pad="2"/>
<connect gate="G$1" pin="GND@2" pad="3"/>
<connect gate="G$1" pin="GND@3" pad="4"/>
<connect gate="G$1" pin="GND@4" pad="5"/>
</connects>
<technologies>
<technology name="">
<attribute name="DESCRIPTION" value=" Conn MMCX PL 0Hz to 6GHz 50Ohm Solder ST Thru-Hole Gold Over Nickel "/>
<attribute name="DIGI-KEY_PART_NUMBER" value="SAM10618-ND"/>
<attribute name="DIGI-KEY_PURCHASE_URL" value="https://www.digikey.ru/product-detail/en/samtec-inc/MMCX-P-P-H-ST-TH1/SAM10618-ND/6561612?utm_source=snapeda&amp;utm_medium=aggregator&amp;utm_campaign=symbol"/>
<attribute name="MF" value="Samtec Inc."/>
<attribute name="MP" value="MMCX-P-P-H-ST-TH1"/>
<attribute name="PACKAGE" value="None"/>
</technology>
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
<library name="pinhead" urn="urn:adsk.eagle:library:325">
<description>&lt;b&gt;Pin Header Connectors&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="1X03" urn="urn:adsk.eagle:footprint:22340/1" library_version="3">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-3.175" y1="1.27" x2="-1.905" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="1.27" x2="-1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="0.635" x2="-1.27" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-0.635" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="0.635" x2="-0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="1.27" x2="0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="1.27" x2="1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="0.635" x2="1.27" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-0.635" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.27" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.27" x2="-1.27" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="0.635" x2="-3.81" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="1.27" x2="-3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="-0.635" x2="-3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.27" x2="-3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="1.27" y1="0.635" x2="1.905" y2="1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="1.27" x2="3.175" y2="1.27" width="0.1524" layer="21"/>
<wire x1="3.175" y1="1.27" x2="3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="3.81" y1="0.635" x2="3.81" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="3.81" y1="-0.635" x2="3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-1.27" x2="1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.27" x2="1.27" y2="-0.635" width="0.1524" layer="21"/>
<pad name="1" x="-2.54" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="0" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="3" x="2.54" y="0" drill="1.016" shape="long" rot="R90"/>
<text x="-3.8862" y="1.8288" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-3.81" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-0.254" y1="-0.254" x2="0.254" y2="0.254" layer="51"/>
<rectangle x1="-2.794" y1="-0.254" x2="-2.286" y2="0.254" layer="51"/>
<rectangle x1="2.286" y1="-0.254" x2="2.794" y2="0.254" layer="51"/>
</package>
<package name="1X03/90" urn="urn:adsk.eagle:footprint:22341/1" library_version="3">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-3.81" y1="-1.905" x2="-1.27" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-1.905" x2="-1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="0.635" x2="-3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="0.635" x2="-3.81" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="6.985" x2="-2.54" y2="1.27" width="0.762" layer="21"/>
<wire x1="-1.27" y1="-1.905" x2="1.27" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-1.905" x2="1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="0.635" x2="-1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="6.985" x2="0" y2="1.27" width="0.762" layer="21"/>
<wire x1="1.27" y1="-1.905" x2="3.81" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="3.81" y1="-1.905" x2="3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="3.81" y1="0.635" x2="1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="6.985" x2="2.54" y2="1.27" width="0.762" layer="21"/>
<pad name="1" x="-2.54" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="0" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="3" x="2.54" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<text x="-4.445" y="-3.81" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="5.715" y="-3.81" size="1.27" layer="27" rot="R90">&gt;VALUE</text>
<rectangle x1="-2.921" y1="0.635" x2="-2.159" y2="1.143" layer="21"/>
<rectangle x1="-0.381" y1="0.635" x2="0.381" y2="1.143" layer="21"/>
<rectangle x1="2.159" y1="0.635" x2="2.921" y2="1.143" layer="21"/>
<rectangle x1="-2.921" y1="-2.921" x2="-2.159" y2="-1.905" layer="21"/>
<rectangle x1="-0.381" y1="-2.921" x2="0.381" y2="-1.905" layer="21"/>
<rectangle x1="2.159" y1="-2.921" x2="2.921" y2="-1.905" layer="21"/>
</package>
<package name="2X08" urn="urn:adsk.eagle:footprint:22373/1" library_version="3">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
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
<wire x1="2.54" y1="-1.905" x2="3.175" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="4.445" y1="-2.54" x2="5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="-1.905" x2="-10.16" y2="1.905" width="0.1524" layer="21"/>
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
<wire x1="7.62" y1="-1.905" x2="6.985" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-1.905" x2="5.715" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="1.905" x2="-7.62" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="1.905" x2="-5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="1.905" x2="-2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="0" y1="1.905" x2="0" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="2.54" y1="1.905" x2="2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="5.08" y1="1.905" x2="5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="7.62" y1="1.905" x2="7.62" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="5.715" y1="-2.54" x2="6.985" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-2.54" x2="4.445" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-2.54" x2="1.905" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-2.54" x2="-0.635" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="-2.54" x2="-3.175" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="-2.54" x2="-5.715" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-9.525" y1="-2.54" x2="-8.255" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="7.62" y1="1.905" x2="8.255" y2="2.54" width="0.1524" layer="21"/>
<wire x1="8.255" y1="2.54" x2="9.525" y2="2.54" width="0.1524" layer="21"/>
<wire x1="9.525" y1="2.54" x2="10.16" y2="1.905" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-1.905" x2="9.525" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="7.62" y1="-1.905" x2="8.255" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="10.16" y1="1.905" x2="10.16" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="8.255" y1="-2.54" x2="9.525" y2="-2.54" width="0.1524" layer="21"/>
<pad name="1" x="-8.89" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="2" x="-8.89" y="1.27" drill="1.016" shape="octagon"/>
<pad name="3" x="-6.35" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="4" x="-6.35" y="1.27" drill="1.016" shape="octagon"/>
<pad name="5" x="-3.81" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="6" x="-3.81" y="1.27" drill="1.016" shape="octagon"/>
<pad name="7" x="-1.27" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="8" x="-1.27" y="1.27" drill="1.016" shape="octagon"/>
<pad name="9" x="1.27" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="10" x="1.27" y="1.27" drill="1.016" shape="octagon"/>
<pad name="11" x="3.81" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="12" x="3.81" y="1.27" drill="1.016" shape="octagon"/>
<pad name="13" x="6.35" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="14" x="6.35" y="1.27" drill="1.016" shape="octagon"/>
<pad name="15" x="8.89" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="16" x="8.89" y="1.27" drill="1.016" shape="octagon"/>
<text x="-10.16" y="3.175" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-10.16" y="-4.445" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-9.144" y1="-1.524" x2="-8.636" y2="-1.016" layer="51"/>
<rectangle x1="-9.144" y1="1.016" x2="-8.636" y2="1.524" layer="51"/>
<rectangle x1="-6.604" y1="1.016" x2="-6.096" y2="1.524" layer="51"/>
<rectangle x1="-6.604" y1="-1.524" x2="-6.096" y2="-1.016" layer="51"/>
<rectangle x1="-4.064" y1="1.016" x2="-3.556" y2="1.524" layer="51"/>
<rectangle x1="-4.064" y1="-1.524" x2="-3.556" y2="-1.016" layer="51"/>
<rectangle x1="-1.524" y1="1.016" x2="-1.016" y2="1.524" layer="51"/>
<rectangle x1="1.016" y1="1.016" x2="1.524" y2="1.524" layer="51"/>
<rectangle x1="3.556" y1="1.016" x2="4.064" y2="1.524" layer="51"/>
<rectangle x1="-1.524" y1="-1.524" x2="-1.016" y2="-1.016" layer="51"/>
<rectangle x1="1.016" y1="-1.524" x2="1.524" y2="-1.016" layer="51"/>
<rectangle x1="3.556" y1="-1.524" x2="4.064" y2="-1.016" layer="51"/>
<rectangle x1="6.096" y1="1.016" x2="6.604" y2="1.524" layer="51"/>
<rectangle x1="6.096" y1="-1.524" x2="6.604" y2="-1.016" layer="51"/>
<rectangle x1="8.636" y1="1.016" x2="9.144" y2="1.524" layer="51"/>
<rectangle x1="8.636" y1="-1.524" x2="9.144" y2="-1.016" layer="51"/>
</package>
<package name="2X08/90" urn="urn:adsk.eagle:footprint:22374/1" library_version="3">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-10.16" y1="-1.905" x2="-7.62" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="-1.905" x2="-7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="0.635" x2="-10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="0.635" x2="-10.16" y2="-1.905" width="0.1524" layer="21"/>
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
<pad name="2" x="-8.89" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="4" x="-6.35" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="6" x="-3.81" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="8" x="-1.27" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="10" x="1.27" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="12" x="3.81" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="14" x="6.35" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="16" x="8.89" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="1" x="-8.89" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="3" x="-6.35" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="5" x="-3.81" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="7" x="-1.27" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="9" x="1.27" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="11" x="3.81" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="13" x="6.35" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="15" x="8.89" y="-6.35" drill="1.016" shape="octagon"/>
<text x="-10.795" y="-3.81" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="12.065" y="-3.81" size="1.27" layer="27" rot="R90">&gt;VALUE</text>
<rectangle x1="-9.271" y1="0.635" x2="-8.509" y2="1.143" layer="21"/>
<rectangle x1="-6.731" y1="0.635" x2="-5.969" y2="1.143" layer="21"/>
<rectangle x1="-4.191" y1="0.635" x2="-3.429" y2="1.143" layer="21"/>
<rectangle x1="-1.651" y1="0.635" x2="-0.889" y2="1.143" layer="21"/>
<rectangle x1="0.889" y1="0.635" x2="1.651" y2="1.143" layer="21"/>
<rectangle x1="3.429" y1="0.635" x2="4.191" y2="1.143" layer="21"/>
<rectangle x1="5.969" y1="0.635" x2="6.731" y2="1.143" layer="21"/>
<rectangle x1="8.509" y1="0.635" x2="9.271" y2="1.143" layer="21"/>
<rectangle x1="-9.271" y1="-2.921" x2="-8.509" y2="-1.905" layer="21"/>
<rectangle x1="-6.731" y1="-2.921" x2="-5.969" y2="-1.905" layer="21"/>
<rectangle x1="-9.271" y1="-5.461" x2="-8.509" y2="-4.699" layer="21"/>
<rectangle x1="-9.271" y1="-4.699" x2="-8.509" y2="-2.921" layer="51"/>
<rectangle x1="-6.731" y1="-4.699" x2="-5.969" y2="-2.921" layer="51"/>
<rectangle x1="-6.731" y1="-5.461" x2="-5.969" y2="-4.699" layer="21"/>
<rectangle x1="-4.191" y1="-2.921" x2="-3.429" y2="-1.905" layer="21"/>
<rectangle x1="-1.651" y1="-2.921" x2="-0.889" y2="-1.905" layer="21"/>
<rectangle x1="-4.191" y1="-5.461" x2="-3.429" y2="-4.699" layer="21"/>
<rectangle x1="-4.191" y1="-4.699" x2="-3.429" y2="-2.921" layer="51"/>
<rectangle x1="-1.651" y1="-4.699" x2="-0.889" y2="-2.921" layer="51"/>
<rectangle x1="-1.651" y1="-5.461" x2="-0.889" y2="-4.699" layer="21"/>
<rectangle x1="0.889" y1="-2.921" x2="1.651" y2="-1.905" layer="21"/>
<rectangle x1="3.429" y1="-2.921" x2="4.191" y2="-1.905" layer="21"/>
<rectangle x1="0.889" y1="-5.461" x2="1.651" y2="-4.699" layer="21"/>
<rectangle x1="0.889" y1="-4.699" x2="1.651" y2="-2.921" layer="51"/>
<rectangle x1="3.429" y1="-4.699" x2="4.191" y2="-2.921" layer="51"/>
<rectangle x1="3.429" y1="-5.461" x2="4.191" y2="-4.699" layer="21"/>
<rectangle x1="5.969" y1="-2.921" x2="6.731" y2="-1.905" layer="21"/>
<rectangle x1="8.509" y1="-2.921" x2="9.271" y2="-1.905" layer="21"/>
<rectangle x1="5.969" y1="-5.461" x2="6.731" y2="-4.699" layer="21"/>
<rectangle x1="5.969" y1="-4.699" x2="6.731" y2="-2.921" layer="51"/>
<rectangle x1="8.509" y1="-4.699" x2="9.271" y2="-2.921" layer="51"/>
<rectangle x1="8.509" y1="-5.461" x2="9.271" y2="-4.699" layer="21"/>
</package>
</packages>
<packages3d>
<package3d name="1X03" urn="urn:adsk.eagle:package:22458/2" type="model" library_version="3">
<description>PIN HEADER</description>
<packageinstances>
<packageinstance name="1X03"/>
</packageinstances>
</package3d>
<package3d name="1X03/90" urn="urn:adsk.eagle:package:22459/2" type="model" library_version="3">
<description>PIN HEADER</description>
<packageinstances>
<packageinstance name="1X03/90"/>
</packageinstances>
</package3d>
<package3d name="2X08" urn="urn:adsk.eagle:package:22481/2" type="model" library_version="3">
<description>PIN HEADER</description>
<packageinstances>
<packageinstance name="2X08"/>
</packageinstances>
</package3d>
<package3d name="2X08/90" urn="urn:adsk.eagle:package:22488/2" type="model" library_version="3">
<description>PIN HEADER</description>
<packageinstances>
<packageinstance name="2X08/90"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="PINHD3" urn="urn:adsk.eagle:symbol:22339/1" library_version="3">
<wire x1="-6.35" y1="-5.08" x2="1.27" y2="-5.08" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-5.08" x2="1.27" y2="5.08" width="0.4064" layer="94"/>
<wire x1="1.27" y1="5.08" x2="-6.35" y2="5.08" width="0.4064" layer="94"/>
<wire x1="-6.35" y1="5.08" x2="-6.35" y2="-5.08" width="0.4064" layer="94"/>
<text x="-6.35" y="5.715" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.35" y="-7.62" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="-2.54" y="2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="2" x="-2.54" y="0" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="3" x="-2.54" y="-2.54" visible="pad" length="short" direction="pas" function="dot"/>
</symbol>
<symbol name="PINH2X8" urn="urn:adsk.eagle:symbol:22372/1" library_version="3">
<wire x1="-6.35" y1="-12.7" x2="8.89" y2="-12.7" width="0.4064" layer="94"/>
<wire x1="8.89" y1="-12.7" x2="8.89" y2="10.16" width="0.4064" layer="94"/>
<wire x1="8.89" y1="10.16" x2="-6.35" y2="10.16" width="0.4064" layer="94"/>
<wire x1="-6.35" y1="10.16" x2="-6.35" y2="-12.7" width="0.4064" layer="94"/>
<text x="-6.35" y="10.795" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.35" y="-15.24" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="-2.54" y="7.62" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="2" x="5.08" y="7.62" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="3" x="-2.54" y="5.08" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="4" x="5.08" y="5.08" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="5" x="-2.54" y="2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="6" x="5.08" y="2.54" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="7" x="-2.54" y="0" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="8" x="5.08" y="0" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="9" x="-2.54" y="-2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="10" x="5.08" y="-2.54" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="11" x="-2.54" y="-5.08" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="12" x="5.08" y="-5.08" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="13" x="-2.54" y="-7.62" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="14" x="5.08" y="-7.62" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="15" x="-2.54" y="-10.16" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="16" x="5.08" y="-10.16" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="PINHD-1X3" urn="urn:adsk.eagle:component:22524/3" prefix="JP" uservalue="yes" library_version="3">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="A" symbol="PINHD3" x="0" y="0"/>
</gates>
<devices>
<device name="" package="1X03">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:22458/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="/90" package="1X03/90">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:22459/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="PINHD-2X8" urn="urn:adsk.eagle:component:22549/3" prefix="JP" uservalue="yes" library_version="3">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="A" symbol="PINH2X8" x="0" y="0"/>
</gates>
<devices>
<device name="" package="2X08">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="10" pad="10"/>
<connect gate="A" pin="11" pad="11"/>
<connect gate="A" pin="12" pad="12"/>
<connect gate="A" pin="13" pad="13"/>
<connect gate="A" pin="14" pad="14"/>
<connect gate="A" pin="15" pad="15"/>
<connect gate="A" pin="16" pad="16"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
<connect gate="A" pin="7" pad="7"/>
<connect gate="A" pin="8" pad="8"/>
<connect gate="A" pin="9" pad="9"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:22481/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="/90" package="2X08/90">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="10" pad="10"/>
<connect gate="A" pin="11" pad="11"/>
<connect gate="A" pin="12" pad="12"/>
<connect gate="A" pin="13" pad="13"/>
<connect gate="A" pin="14" pad="14"/>
<connect gate="A" pin="15" pad="15"/>
<connect gate="A" pin="16" pad="16"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
<connect gate="A" pin="7" pad="7"/>
<connect gate="A" pin="8" pad="8"/>
<connect gate="A" pin="9" pad="9"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:22488/2"/>
</package3dinstances>
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
<class number="0" name="default" width="0.2" drill="0">
<clearance class="0" value="0.2"/>
</class>
<class number="1" name="power" width="0.5" drill="0">
<clearance class="1" value="0.2"/>
</class>
<class number="2" name="rf" width="0.5" drill="0">
<clearance class="2" value="0.0645125"/>
</class>
</classes>
<parts>
<part name="USER_PORT" library="SAMTEC-CLP-110-02-X-D" deviceset="SAMTEC-CLP-110-02-X-D" device="J"/>
<part name="GPS" library="MMCX-P-P-X-ST-TH1" deviceset="MMCX-P-P-X-ST-TH1" device=""/>
<part name="ANT" library="MMCX-P-P-X-ST-TH1" deviceset="MMCX-P-P-X-ST-TH1" device=""/>
<part name="GND1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND2" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND3" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND4" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GPS_OUT" library="U.FL-R-SMT_01_" deviceset="U.FL-R-SMT(01)" device=""/>
<part name="ANT_IN" library="U.FL-R-SMT_01_" deviceset="U.FL-R-SMT(01)" device=""/>
<part name="GND5" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND6" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND7" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X3" device="" package3d_urn="urn:adsk.eagle:package:22458/2"/>
<part name="SPLY_OUT" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X3" device="" package3d_urn="urn:adsk.eagle:package:22458/2"/>
<part name="JP3" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-2X8" device="" package3d_urn="urn:adsk.eagle:package:22481/2"/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="USER_PORT" gate="A" x="71.12" y="68.58" smashed="yes">
<attribute name="NAME" x="71.12" y="76.208490625" size="2.544240625" layer="95"/>
<attribute name="VALUE" x="71.12" y="35.4987" size="2.290240625" layer="96"/>
</instance>
<instance part="GPS" gate="G$1" x="81.28" y="147.32" smashed="yes">
<attribute name="NAME" x="76.19325" y="154.95011875" size="1.271690625" layer="95"/>
<attribute name="VALUE" x="76.19246875" y="138.416809375" size="1.27188125" layer="96"/>
</instance>
<instance part="ANT" gate="G$1" x="81.28" y="167.64" smashed="yes">
<attribute name="NAME" x="76.19325" y="175.27011875" size="1.271690625" layer="95"/>
<attribute name="VALUE" x="76.19246875" y="158.736809375" size="1.27188125" layer="96"/>
</instance>
<instance part="GND1" gate="1" x="99.06" y="157.48" smashed="yes">
<attribute name="VALUE" x="96.52" y="154.94" size="1.778" layer="96"/>
</instance>
<instance part="GND2" gate="1" x="63.5" y="157.48" smashed="yes">
<attribute name="VALUE" x="60.96" y="154.94" size="1.778" layer="96"/>
</instance>
<instance part="GND3" gate="1" x="99.06" y="137.16" smashed="yes">
<attribute name="VALUE" x="96.52" y="134.62" size="1.778" layer="96"/>
</instance>
<instance part="GND4" gate="1" x="63.5" y="137.16" smashed="yes">
<attribute name="VALUE" x="60.96" y="134.62" size="1.778" layer="96"/>
</instance>
<instance part="GPS_OUT" gate="G$1" x="35.56" y="149.86" smashed="yes" rot="MR0">
<attribute name="NAME" x="39.37856875" y="153.93313125" size="1.27285" layer="95" rot="MR0"/>
<attribute name="VALUE" x="39.88781875" y="144.2593" size="1.27288125" layer="96" rot="MR0"/>
</instance>
<instance part="ANT_IN" gate="G$1" x="35.56" y="170.18" smashed="yes" rot="MR0">
<attribute name="NAME" x="39.37856875" y="174.25313125" size="1.27285" layer="95" rot="MR0"/>
<attribute name="VALUE" x="39.88781875" y="164.5793" size="1.27288125" layer="96" rot="MR0"/>
</instance>
<instance part="GND5" gate="1" x="48.26" y="137.16" smashed="yes">
<attribute name="VALUE" x="45.72" y="134.62" size="1.778" layer="96"/>
</instance>
<instance part="GND6" gate="1" x="48.26" y="157.48" smashed="yes">
<attribute name="VALUE" x="45.72" y="154.94" size="1.778" layer="96"/>
</instance>
<instance part="GND7" gate="1" x="-17.78" y="83.82" smashed="yes">
<attribute name="VALUE" x="-20.32" y="81.28" size="1.778" layer="96"/>
</instance>
<instance part="GND" gate="A" x="-5.08" y="99.06" smashed="yes" rot="R90">
<attribute name="NAME" x="-10.795" y="92.71" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="2.54" y="92.71" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="SPLY_OUT" gate="A" x="-5.08" y="114.3" smashed="yes" rot="R270">
<attribute name="NAME" x="0.635" y="120.65" size="1.778" layer="95" rot="R270"/>
<attribute name="VALUE" x="-12.7" y="120.65" size="1.778" layer="96" rot="R270"/>
</instance>
<instance part="JP3" gate="A" x="78.74" y="7.62" smashed="yes" rot="MR180">
<attribute name="NAME" x="72.39" y="-3.175" size="1.778" layer="95" rot="MR180"/>
<attribute name="VALUE" x="72.39" y="22.86" size="1.778" layer="96" rot="MR180"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="GND" class="1">
<segment>
<pinref part="GND2" gate="1" pin="GND"/>
<pinref part="ANT" gate="G$1" pin="GND@1"/>
<wire x1="63.5" y1="160.02" x2="63.5" y2="162.56" width="0.1524" layer="91"/>
<wire x1="63.5" y1="162.56" x2="63.5" y2="166.37" width="0.1524" layer="91"/>
<wire x1="63.5" y1="166.37" x2="71.12" y2="166.37" width="0.1524" layer="91"/>
<pinref part="ANT" gate="G$1" pin="GND@3"/>
<wire x1="71.12" y1="163.83" x2="68.58" y2="163.83" width="0.1524" layer="91"/>
<wire x1="68.58" y1="163.83" x2="68.58" y2="162.56" width="0.1524" layer="91"/>
<wire x1="68.58" y1="162.56" x2="63.5" y2="162.56" width="0.1524" layer="91"/>
<junction x="63.5" y="162.56"/>
</segment>
<segment>
<pinref part="ANT" gate="G$1" pin="GND@2"/>
<pinref part="GND1" gate="1" pin="GND"/>
<wire x1="91.44" y1="166.37" x2="99.06" y2="166.37" width="0.1524" layer="91"/>
<wire x1="99.06" y1="166.37" x2="99.06" y2="162.56" width="0.1524" layer="91"/>
<pinref part="ANT" gate="G$1" pin="GND@4"/>
<wire x1="99.06" y1="162.56" x2="99.06" y2="160.02" width="0.1524" layer="91"/>
<wire x1="91.44" y1="163.83" x2="93.98" y2="163.83" width="0.1524" layer="91"/>
<wire x1="93.98" y1="163.83" x2="93.98" y2="162.56" width="0.1524" layer="91"/>
<wire x1="93.98" y1="162.56" x2="99.06" y2="162.56" width="0.1524" layer="91"/>
<junction x="99.06" y="162.56"/>
</segment>
<segment>
<pinref part="GPS" gate="G$1" pin="GND@2"/>
<pinref part="GND3" gate="1" pin="GND"/>
<wire x1="91.44" y1="146.05" x2="99.06" y2="146.05" width="0.1524" layer="91"/>
<wire x1="99.06" y1="146.05" x2="99.06" y2="142.24" width="0.1524" layer="91"/>
<pinref part="GPS" gate="G$1" pin="GND@4"/>
<wire x1="99.06" y1="142.24" x2="99.06" y2="139.7" width="0.1524" layer="91"/>
<wire x1="91.44" y1="143.51" x2="93.98" y2="143.51" width="0.1524" layer="91"/>
<wire x1="93.98" y1="143.51" x2="93.98" y2="142.24" width="0.1524" layer="91"/>
<wire x1="93.98" y1="142.24" x2="99.06" y2="142.24" width="0.1524" layer="91"/>
<junction x="99.06" y="142.24"/>
</segment>
<segment>
<pinref part="GPS" gate="G$1" pin="GND@1"/>
<pinref part="GND4" gate="1" pin="GND"/>
<wire x1="71.12" y1="146.05" x2="63.5" y2="146.05" width="0.1524" layer="91"/>
<wire x1="63.5" y1="146.05" x2="63.5" y2="142.24" width="0.1524" layer="91"/>
<pinref part="GPS" gate="G$1" pin="GND@3"/>
<wire x1="63.5" y1="142.24" x2="63.5" y2="139.7" width="0.1524" layer="91"/>
<wire x1="71.12" y1="143.51" x2="68.58" y2="143.51" width="0.1524" layer="91"/>
<wire x1="68.58" y1="143.51" x2="68.58" y2="142.24" width="0.1524" layer="91"/>
<wire x1="68.58" y1="142.24" x2="63.5" y2="142.24" width="0.1524" layer="91"/>
<junction x="63.5" y="142.24"/>
</segment>
<segment>
<pinref part="GPS_OUT" gate="G$1" pin="GND"/>
<pinref part="GND5" gate="1" pin="GND"/>
<wire x1="45.72" y1="147.32" x2="48.26" y2="147.32" width="0.1524" layer="91"/>
<wire x1="48.26" y1="147.32" x2="48.26" y2="139.7" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="ANT_IN" gate="G$1" pin="GND"/>
<pinref part="GND6" gate="1" pin="GND"/>
<wire x1="45.72" y1="167.64" x2="48.26" y2="167.64" width="0.1524" layer="91"/>
<wire x1="48.26" y1="167.64" x2="48.26" y2="160.02" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="USER_PORT" gate="A" pin="8"/>
<label x="104.14" y="60.96" size="1.778" layer="95"/>
<wire x1="101.6" y1="60.96" x2="96.52" y2="60.96" width="0.1524" layer="91"/>
<junction x="101.6" y="60.96"/>
<pinref part="USER_PORT" gate="A" pin="4"/>
<wire x1="101.6" y1="48.26" x2="101.6" y2="60.96" width="0.1524" layer="91"/>
<wire x1="101.6" y1="66.04" x2="96.52" y2="66.04" width="0.1524" layer="91"/>
<junction x="101.6" y="66.04"/>
<wire x1="101.6" y1="78.74" x2="101.6" y2="66.04" width="0.1524" layer="91"/>
<wire x1="60.96" y1="78.74" x2="101.6" y2="78.74" width="0.1524" layer="91"/>
<pinref part="USER_PORT" gate="A" pin="3"/>
<wire x1="66.04" y1="66.04" x2="60.96" y2="66.04" width="0.1524" layer="91"/>
<wire x1="60.96" y1="66.04" x2="60.96" y2="78.74" width="0.1524" layer="91"/>
<junction x="60.96" y="66.04"/>
<wire x1="60.96" y1="66.04" x2="10.16" y2="66.04" width="0.1524" layer="91"/>
<label x="33.02" y="66.04" size="1.778" layer="95"/>
<label x="111.76" y="66.04" size="1.778" layer="95"/>
<wire x1="101.6" y1="66.04" x2="101.6" y2="60.96" width="0.1524" layer="91"/>
<pinref part="USER_PORT" gate="A" pin="18"/>
<wire x1="96.52" y1="48.26" x2="101.6" y2="48.26" width="0.1524" layer="91"/>
<label x="104.14" y="48.26" size="1.778" layer="95"/>
<pinref part="USER_PORT" gate="A" pin="15"/>
<label x="43.18" y="50.8" size="1.778" layer="95"/>
<wire x1="60.96" y1="50.8" x2="66.04" y2="50.8" width="0.1524" layer="91"/>
<wire x1="60.96" y1="66.04" x2="60.96" y2="50.8" width="0.1524" layer="91"/>
<wire x1="60.96" y1="50.8" x2="43.18" y2="50.8" width="0.1524" layer="91"/>
<junction x="60.96" y="50.8"/>
<wire x1="101.6" y1="48.26" x2="104.14" y2="48.26" width="0.1524" layer="91"/>
<junction x="101.6" y="48.26"/>
<wire x1="101.6" y1="60.96" x2="104.14" y2="60.96" width="0.1524" layer="91"/>
<wire x1="101.6" y1="66.04" x2="147.32" y2="66.04" width="0.1524" layer="91"/>
<pinref part="JP3" gate="A" pin="3"/>
<wire x1="10.16" y1="66.04" x2="10.16" y2="2.54" width="0.1524" layer="91"/>
<wire x1="10.16" y1="2.54" x2="76.2" y2="2.54" width="0.1524" layer="91"/>
<wire x1="147.32" y1="66.04" x2="147.32" y2="2.54" width="0.1524" layer="91"/>
<pinref part="JP3" gate="A" pin="4"/>
<wire x1="147.32" y1="2.54" x2="83.82" y2="2.54" width="0.1524" layer="91"/>
<label x="38.1" y="2.54" size="1.778" layer="95"/>
<label x="99.06" y="2.54" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="GND7" gate="1" pin="GND"/>
<wire x1="-17.78" y1="86.36" x2="-17.78" y2="88.9" width="0.1524" layer="91"/>
<wire x1="-17.78" y1="88.9" x2="-7.62" y2="88.9" width="0.1524" layer="91"/>
<label x="15.24" y="88.9" size="1.778" layer="95"/>
<pinref part="GND" gate="A" pin="1"/>
<wire x1="-7.62" y1="88.9" x2="-5.08" y2="88.9" width="0.1524" layer="91"/>
<wire x1="-5.08" y1="88.9" x2="-2.54" y2="88.9" width="0.1524" layer="91"/>
<wire x1="-2.54" y1="88.9" x2="12.7" y2="88.9" width="0.1524" layer="91"/>
<wire x1="-7.62" y1="96.52" x2="-7.62" y2="88.9" width="0.1524" layer="91"/>
<junction x="-7.62" y="88.9"/>
<pinref part="GND" gate="A" pin="2"/>
<wire x1="-5.08" y1="96.52" x2="-5.08" y2="88.9" width="0.1524" layer="91"/>
<junction x="-5.08" y="88.9"/>
<pinref part="GND" gate="A" pin="3"/>
<wire x1="-2.54" y1="96.52" x2="-2.54" y2="88.9" width="0.1524" layer="91"/>
<junction x="-2.54" y="88.9"/>
</segment>
</net>
<net name="NETWORK_AVAILABLE" class="0">
<segment>
<pinref part="USER_PORT" gate="A" pin="19"/>
<wire x1="25.4" y1="45.72" x2="66.04" y2="45.72" width="0.1524" layer="91"/>
<label x="33.02" y="45.72" size="1.778" layer="95"/>
<pinref part="JP3" gate="A" pin="15"/>
<wire x1="25.4" y1="45.72" x2="25.4" y2="17.78" width="0.1524" layer="91"/>
<wire x1="25.4" y1="17.78" x2="76.2" y2="17.78" width="0.1524" layer="91"/>
<label x="38.1" y="17.78" size="1.778" layer="95"/>
</segment>
</net>
<net name="SUPPLY_OUT" class="0">
<segment>
<pinref part="USER_PORT" gate="A" pin="20"/>
<wire x1="96.52" y1="45.72" x2="134.62" y2="45.72" width="0.1524" layer="91"/>
<label x="111.76" y="45.72" size="1.778" layer="95"/>
<pinref part="JP3" gate="A" pin="16"/>
<wire x1="134.62" y1="45.72" x2="134.62" y2="17.78" width="0.1524" layer="91"/>
<wire x1="134.62" y1="17.78" x2="99.06" y2="17.78" width="0.1524" layer="91"/>
<pinref part="JP3" gate="A" pin="14"/>
<wire x1="99.06" y1="17.78" x2="83.82" y2="17.78" width="0.1524" layer="91"/>
<wire x1="83.82" y1="15.24" x2="99.06" y2="15.24" width="0.1524" layer="91"/>
<wire x1="99.06" y1="15.24" x2="99.06" y2="17.78" width="0.1524" layer="91"/>
<junction x="99.06" y="17.78"/>
<label x="99.06" y="17.78" size="1.778" layer="95"/>
</segment>
<segment>
<label x="15.24" y="124.46" size="1.778" layer="95"/>
<wire x1="-17.78" y1="124.46" x2="-7.62" y2="124.46" width="0.1524" layer="91"/>
<pinref part="SPLY_OUT" gate="A" pin="1"/>
<wire x1="-7.62" y1="124.46" x2="-5.08" y2="124.46" width="0.1524" layer="91"/>
<wire x1="-5.08" y1="124.46" x2="-2.54" y2="124.46" width="0.1524" layer="91"/>
<wire x1="-2.54" y1="124.46" x2="12.7" y2="124.46" width="0.1524" layer="91"/>
<wire x1="-2.54" y1="116.84" x2="-2.54" y2="124.46" width="0.1524" layer="91"/>
<junction x="-2.54" y="124.46"/>
<pinref part="SPLY_OUT" gate="A" pin="2"/>
<wire x1="-5.08" y1="116.84" x2="-5.08" y2="124.46" width="0.1524" layer="91"/>
<junction x="-5.08" y="124.46"/>
<pinref part="SPLY_OUT" gate="A" pin="3"/>
<wire x1="-7.62" y1="116.84" x2="-7.62" y2="124.46" width="0.1524" layer="91"/>
<junction x="-7.62" y="124.46"/>
</segment>
</net>
<net name="RESERVED_1" class="0">
<segment>
<pinref part="USER_PORT" gate="A" pin="16"/>
<label x="104.14" y="50.8" size="1.778" layer="95"/>
<wire x1="96.52" y1="50.8" x2="103.9876" y2="50.8" width="0.1524" layer="91"/>
</segment>
</net>
<net name="DF_DTR" class="0">
<segment>
<pinref part="USER_PORT" gate="A" pin="14"/>
<wire x1="96.52" y1="53.34" x2="137.16" y2="53.34" width="0.1524" layer="91"/>
<label x="111.76" y="53.34" size="1.778" layer="95"/>
<pinref part="JP3" gate="A" pin="12"/>
<wire x1="83.82" y1="12.7" x2="137.16" y2="12.7" width="0.1524" layer="91"/>
<wire x1="137.16" y1="12.7" x2="137.16" y2="53.34" width="0.1524" layer="91"/>
<label x="99.06" y="12.7" size="1.778" layer="95"/>
</segment>
</net>
<net name="DF_RI" class="0">
<segment>
<pinref part="USER_PORT" gate="A" pin="12"/>
<wire x1="139.7" y1="55.88" x2="96.52" y2="55.88" width="0.1524" layer="91"/>
<label x="111.76" y="55.88" size="1.778" layer="95"/>
<pinref part="JP3" gate="A" pin="10"/>
<wire x1="83.82" y1="10.16" x2="139.7" y2="10.16" width="0.1524" layer="91"/>
<wire x1="139.7" y1="10.16" x2="139.7" y2="55.88" width="0.1524" layer="91"/>
<label x="99.06" y="10.16" size="1.778" layer="95"/>
</segment>
</net>
<net name="DF_DSR" class="0">
<segment>
<pinref part="USER_PORT" gate="A" pin="10"/>
<wire x1="96.52" y1="58.42" x2="142.24" y2="58.42" width="0.1524" layer="91"/>
<label x="111.76" y="58.42" size="1.778" layer="95"/>
<wire x1="142.24" y1="58.42" x2="142.24" y2="7.62" width="0.1524" layer="91"/>
<pinref part="JP3" gate="A" pin="8"/>
<wire x1="142.24" y1="7.62" x2="83.82" y2="7.62" width="0.1524" layer="91"/>
<label x="99.06" y="7.62" size="1.778" layer="95"/>
</segment>
</net>
<net name="DF_S_TX" class="0">
<segment>
<pinref part="USER_PORT" gate="A" pin="6"/>
<wire x1="96.52" y1="63.5" x2="144.78" y2="63.5" width="0.1524" layer="91"/>
<label x="111.76" y="63.5" size="1.778" layer="95"/>
<pinref part="JP3" gate="A" pin="6"/>
<wire x1="83.82" y1="5.08" x2="144.78" y2="5.08" width="0.1524" layer="91"/>
<wire x1="144.78" y1="5.08" x2="144.78" y2="63.5" width="0.1524" layer="91"/>
<label x="99.06" y="5.08" size="1.778" layer="95"/>
</segment>
</net>
<net name="RESERVED_2\" class="0">
<segment>
<pinref part="USER_PORT" gate="A" pin="17"/>
<label x="43.18" y="48.26" size="1.778" layer="95"/>
<wire x1="66.04" y1="48.26" x2="43.3324" y2="48.26" width="0.1524" layer="91"/>
</segment>
</net>
<net name="DF_RTS" class="0">
<segment>
<pinref part="USER_PORT" gate="A" pin="13"/>
<wire x1="66.04" y1="53.34" x2="22.86" y2="53.34" width="0.1524" layer="91"/>
<label x="33.02" y="53.34" size="1.778" layer="95"/>
<wire x1="22.86" y1="53.34" x2="22.86" y2="15.24" width="0.1524" layer="91"/>
<wire x1="22.86" y1="15.24" x2="76.2" y2="15.24" width="0.1524" layer="91"/>
<pinref part="JP3" gate="A" pin="13"/>
<label x="38.1" y="15.24" size="1.778" layer="95"/>
</segment>
</net>
<net name="DF_CTS" class="0">
<segment>
<pinref part="USER_PORT" gate="A" pin="11"/>
<wire x1="20.32" y1="55.88" x2="66.04" y2="55.88" width="0.1524" layer="91"/>
<label x="33.02" y="55.88" size="1.778" layer="95"/>
<pinref part="JP3" gate="A" pin="11"/>
<wire x1="20.32" y1="55.88" x2="20.32" y2="12.7" width="0.1524" layer="91"/>
<wire x1="20.32" y1="12.7" x2="76.2" y2="12.7" width="0.1524" layer="91"/>
<label x="38.1" y="12.7" size="1.778" layer="95"/>
</segment>
</net>
<net name="DF_DCD" class="0">
<segment>
<pinref part="USER_PORT" gate="A" pin="9"/>
<wire x1="66.04" y1="58.42" x2="17.78" y2="58.42" width="0.1524" layer="91"/>
<label x="33.02" y="58.42" size="1.778" layer="95"/>
<pinref part="JP3" gate="A" pin="9"/>
<wire x1="17.78" y1="58.42" x2="17.78" y2="10.16" width="0.1524" layer="91"/>
<wire x1="17.78" y1="10.16" x2="76.2" y2="10.16" width="0.1524" layer="91"/>
<label x="38.1" y="10.16" size="1.778" layer="95"/>
</segment>
</net>
<net name="DF_S_RX" class="0">
<segment>
<pinref part="USER_PORT" gate="A" pin="7"/>
<wire x1="66.04" y1="60.96" x2="15.24" y2="60.96" width="0.1524" layer="91"/>
<label x="33.02" y="60.96" size="1.778" layer="95"/>
<pinref part="JP3" gate="A" pin="7"/>
<wire x1="15.24" y1="60.96" x2="15.24" y2="7.62" width="0.1524" layer="91"/>
<wire x1="15.24" y1="7.62" x2="76.2" y2="7.62" width="0.1524" layer="91"/>
<label x="38.1" y="7.62" size="1.778" layer="95"/>
</segment>
</net>
<net name="ON_OFF" class="0">
<segment>
<pinref part="USER_PORT" gate="A" pin="5"/>
<wire x1="66.04" y1="63.5" x2="12.7" y2="63.5" width="0.1524" layer="91"/>
<label x="33.02" y="63.5" size="1.778" layer="95"/>
<pinref part="JP3" gate="A" pin="5"/>
<wire x1="12.7" y1="63.5" x2="12.7" y2="5.08" width="0.1524" layer="91"/>
<wire x1="12.7" y1="5.08" x2="76.2" y2="5.08" width="0.1524" layer="91"/>
<label x="38.1" y="5.08" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$21" class="2">
<segment>
<pinref part="ANT" gate="G$1" pin="1"/>
<wire x1="71.12" y1="171.45" x2="68.58" y2="171.45" width="0.1524" layer="91"/>
<wire x1="68.58" y1="171.45" x2="68.58" y2="172.72" width="0.1524" layer="91"/>
<pinref part="ANT_IN" gate="G$1" pin="SIG"/>
<wire x1="45.72" y1="172.72" x2="68.58" y2="172.72" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$22" class="2">
<segment>
<pinref part="GPS" gate="G$1" pin="1"/>
<wire x1="71.12" y1="151.13" x2="68.58" y2="151.13" width="0.1524" layer="91"/>
<wire x1="68.58" y1="151.13" x2="68.58" y2="152.4" width="0.1524" layer="91"/>
<pinref part="GPS_OUT" gate="G$1" pin="SIG"/>
<wire x1="45.72" y1="152.4" x2="68.58" y2="152.4" width="0.1524" layer="91"/>
</segment>
</net>
<net name="VCC5" class="1">
<segment>
<pinref part="USER_PORT" gate="A" pin="2"/>
<wire x1="96.52" y1="68.58" x2="99.06" y2="68.58" width="0.1524" layer="91"/>
<label x="111.76" y="68.58" size="1.778" layer="95"/>
<pinref part="USER_PORT" gate="A" pin="1"/>
<wire x1="99.06" y1="68.58" x2="149.86" y2="68.58" width="0.1524" layer="91"/>
<wire x1="66.04" y1="68.58" x2="63.5" y2="68.58" width="0.1524" layer="91"/>
<label x="33.02" y="68.58" size="1.778" layer="95"/>
<wire x1="63.5" y1="68.58" x2="7.62" y2="68.58" width="0.1524" layer="91"/>
<wire x1="63.5" y1="68.58" x2="63.5" y2="76.2" width="0.1524" layer="91"/>
<wire x1="63.5" y1="76.2" x2="99.06" y2="76.2" width="0.1524" layer="91"/>
<junction x="63.5" y="68.58"/>
<wire x1="99.06" y1="76.2" x2="99.06" y2="68.58" width="0.1524" layer="91"/>
<junction x="99.06" y="68.58"/>
<pinref part="JP3" gate="A" pin="1"/>
<wire x1="7.62" y1="68.58" x2="7.62" y2="0" width="0.1524" layer="91"/>
<wire x1="7.62" y1="0" x2="76.2" y2="0" width="0.1524" layer="91"/>
<pinref part="JP3" gate="A" pin="2"/>
<wire x1="149.86" y1="68.58" x2="149.86" y2="0" width="0.1524" layer="91"/>
<wire x1="149.86" y1="0" x2="83.82" y2="0" width="0.1524" layer="91"/>
<label x="38.1" y="0" size="1.778" layer="95"/>
<label x="99.06" y="0" size="1.778" layer="95"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
<errors>
<approved hash="103,1,71.12,151.13,GPS,1,N$22,,,"/>
<approved hash="103,1,71.12,171.45,ANT,1,N$21,,,"/>
<approved hash="106,1,96.52,50.8,RESERVED_1,,,,,"/>
<approved hash="106,1,66.04,48.26,RESERVED_2\\,,,,,"/>
<approved hash="113,1,5.03767,113.32,SV1,,,,,"/>
<approved hash="113,1,22.8177,113.32,SV2,,,,,"/>
<approved hash="113,1,119.338,113.32,SV3,,,,,"/>
</errors>
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
</compatibility>
</eagle>
