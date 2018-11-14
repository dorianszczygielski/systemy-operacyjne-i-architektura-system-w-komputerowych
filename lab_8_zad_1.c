<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<project source="2.7.1" version="1.0">
This file is intended to be loaded by Logisim (http://www.cburch.com/logisim/).
<lib desc="#Wiring" name="0"/>
  <lib desc="#Gates" name="1"/>
  <lib desc="#Plexers" name="2"/>
  <lib desc="#Arithmetic" name="3"/>
  <lib desc="#Memory" name="4"/>
  <lib desc="#I/O" name="5"/>
  <lib desc="#Base" name="6">
    <tool name="Text Tool">
      <a name="text" val=""/>
      <a name="font" val="SansSerif plain 12"/>
      <a name="halign" val="center"/>
      <a name="valign" val="base"/>
    </tool>
  </lib>
  <main name="main"/>
  <options>
    <a name="gateUndefined" val="ignore"/>
    <a name="simlimit" val="1000"/>
    <a name="simrand" val="0"/>
  </options>
  <mappings>
    <tool lib="6" map="Button2" name="Menu Tool"/>
    <tool lib="6" map="Button3" name="Menu Tool"/>
    <tool lib="6" map="Ctrl Button1" name="Menu Tool"/>
  </mappings>
  <toolbar>
    <tool lib="6" name="Poke Tool"/>
    <tool lib="6" name="Edit Tool"/>
    <tool lib="6" name="Text Tool">
      <a name="text" val=""/>
      <a name="font" val="SansSerif plain 12"/>
      <a name="halign" val="center"/>
      <a name="valign" val="base"/>
    </tool>
    <sep/>
    <tool lib="0" name="Pin">
      <a name="tristate" val="false"/>
    </tool>
    <tool lib="0" name="Pin">
      <a name="facing" val="west"/>
      <a name="output" val="true"/>
      <a name="labelloc" val="east"/>
    </tool>
    <tool lib="1" name="NOT Gate"/>
    <tool lib="1" name="AND Gate"/>
    <tool lib="1" name="OR Gate"/>
  </toolbar>
  <circuit name="main">
    <a name="circuit" val="main"/>
    <a name="clabel" val=""/>
    <a name="clabelup" val="east"/>
    <a name="clabelfont" val="SansSerif plain 12"/>
    <wire from="(690,170)" to="(690,180)"/>
    <wire from="(680,30)" to="(680,40)"/>
    <wire from="(50,240)" to="(110,240)"/>
    <wire from="(220,250)" to="(220,260)"/>
    <wire from="(640,70)" to="(640,200)"/>
    <wire from="(560,240)" to="(620,240)"/>
    <wire from="(140,670)" to="(190,670)"/>
    <wire from="(740,210)" to="(800,210)"/>
    <wire from="(310,490)" to="(310,510)"/>
    <wire from="(710,160)" to="(750,160)"/>
    <wire from="(670,180)" to="(670,210)"/>
    <wire from="(140,510)" to="(310,510)"/>
    <wire from="(90,680)" to="(90,700)"/>
    <wire from="(280,240)" to="(320,240)"/>
    <wire from="(380,240)" to="(420,240)"/>
    <wire from="(680,50)" to="(680,70)"/>
    <wire from="(150,230)" to="(250,230)"/>
    <wire from="(110,670)" to="(140,670)"/>
    <wire from="(230,310)" to="(260,310)"/>
    <wire from="(220,250)" to="(250,250)"/>
    <wire from="(140,510)" to="(140,670)"/>
    <wire from="(670,180)" to="(690,180)"/>
    <wire from="(350,240)" to="(380,240)"/>
    <wire from="(310,320)" to="(330,320)"/>
    <wire from="(100,180)" to="(100,220)"/>
    <wire from="(100,180)" to="(380,180)"/>
    <wire from="(640,210)" to="(670,210)"/>
    <wire from="(470,340)" to="(490,340)"/>
    <wire from="(200,260)" to="(220,260)"/>
    <wire from="(260,260)" to="(260,310)"/>
    <wire from="(100,220)" to="(110,220)"/>
    <wire from="(330,260)" to="(330,320)"/>
    <wire from="(380,180)" to="(380,240)"/>
    <wire from="(640,220)" to="(720,220)"/>
    <wire from="(640,230)" to="(720,230)"/>
    <wire from="(330,380)" to="(330,440)"/>
    <wire from="(680,30)" to="(760,30)"/>
    <wire from="(680,70)" to="(760,70)"/>
    <wire from="(490,280)" to="(490,340)"/>
    <comp lib="0" loc="(310,320)" name="Clock"/>
    <comp lib="3" loc="(150,230)" name="Adder"/>
    <comp lib="1" loc="(330,440)" name="OR Gate">
      <a name="facing" val="north"/>
      <a name="label" val="OR"/>
    </comp>
    <comp lib="0" loc="(200,260)" name="Tunnel">
      <a name="facing" val="east"/>
      <a name="width" val="8"/>
      <a name="label" val="Adres"/>
    </comp>
    <comp lib="0" loc="(760,30)" name="Tunnel">
      <a name="width" val="2"/>
      <a name="label" val="Dreg"/>
    </comp>
    <comp lib="0" loc="(800,210)" name="Tunnel">
      <a name="width" val="8"/>
      <a name="label" val="Adres"/>
    </comp>
    <comp lib="0" loc="(760,70)" name="Tunnel">
      <a name="width" val="2"/>
      <a name="label" val="Sreg"/>
    </comp>
    <comp lib="0" loc="(740,210)" name="Splitter">
      <a name="facing" val="west"/>
      <a name="incoming" val="8"/>
      <a name="bit1" val="0"/>
      <a name="bit2" val="0"/>
      <a name="bit3" val="0"/>
      <a name="bit4" val="1"/>
      <a name="bit5" val="1"/>
      <a name="bit6" val="1"/>
      <a name="bit7" val="1"/>
    </comp>
    <comp lib="0" loc="(90,700)" name="Tunnel">
      <a name="facing" val="north"/>
      <a name="width" val="4"/>
      <a name="label" val="Icode"/>
    </comp>
    <comp lib="2" loc="(280,240)" name="Multiplexer">
      <a name="width" val="8"/>
    </comp>
    <comp lib="4" loc="(350,240)" name="Register"/>
    <comp lib="4" loc="(560,240)" name="RAM">
      <a name="dataWidth" val="16"/>
    </comp>
    <comp lib="0" loc="(230,310)" name="Tunnel">
      <a name="facing" val="east"/>
      <a name="label" val="skok"/>
    </comp>
    <comp lib="0" loc="(710,160)" name="Splitter">
      <a name="facing" val="west"/>
      <a name="fanout" val="1"/>
      <a name="incoming" val="4"/>
      <a name="bit1" val="0"/>
      <a name="bit2" val="0"/>
      <a name="bit3" val="0"/>
    </comp>
    <comp lib="0" loc="(660,60)" name="Splitter">
      <a name="incoming" val="4"/>
      <a name="bit1" val="0"/>
      <a name="bit2" val="1"/>
      <a name="bit3" val="1"/>
    </comp>
    <comp lib="0" loc="(330,380)" name="Tunnel">
      <a name="facing" val="south"/>
      <a name="label" val="skok"/>
    </comp>
    <comp lib="0" loc="(750,160)" name="Tunnel">
      <a name="width" val="4"/>
      <a name="label" val="Icode"/>
    </comp>
    <comp lib="2" loc="(90,680)" name="Decoder">
      <a name="select" val="4"/>
    </comp>
    <comp lib="0" loc="(190,670)" name="Tunnel">
      <a name="label" val="JMP"/>
    </comp>
    <comp lib="0" loc="(50,240)" name="Constant">
      <a name="width" val="8"/>
    </comp>
    <comp lib="0" loc="(470,340)" name="Clock"/>
    <comp lib="0" loc="(620,240)" name="Splitter">
      <a name="fanout" val="4"/>
      <a name="incoming" val="16"/>
      <a name="bit1" val="0"/>
      <a name="bit2" val="0"/>
      <a name="bit3" val="0"/>
      <a name="bit4" val="1"/>
      <a name="bit5" val="1"/>
      <a name="bit6" val="1"/>
      <a name="bit7" val="1"/>
      <a name="bit8" val="2"/>
      <a name="bit9" val="2"/>
      <a name="bit10" val="2"/>
      <a name="bit11" val="2"/>
      <a name="bit12" val="3"/>
      <a name="bit13" val="3"/>
      <a name="bit14" val="3"/>
      <a name="bit15" val="3"/>
    </comp>
    <comp lib="0" loc="(640,70)" name="Splitter">
      <a name="fanout" val="1"/>
      <a name="incoming" val="4"/>
      <a name="bit1" val="0"/>
      <a name="bit2" val="0"/>
      <a name="bit3" val="0"/>
    </comp>
  </circuit>
</project>
