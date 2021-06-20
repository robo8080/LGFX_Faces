/***************************************************
Copyright (c) 2020 Luis Llamas
(www.luisllamas.es)

This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License along with this program.  If not, see <http://www.gnu.org/licenses
****************************************************/

#define LGFX_AUTODETECT // 自動認識 (M5Stack, M5StickC/CPlus, ODROID-GO, TTGO T-Watch, TTGO T-Wristband, LoLin D32 Pro, ESP-WROVER-KIT)
#include <LovyanGFX.hpp>
#include <LGFX_TFT_eSPI.hpp>

 static TFT_eSPI lcd;               // TFT_eSPIがLGFXの別名として定義されます。

#include "Face.h"

#define WIDTH  240
#define HEIGHT 320
#define EYE 100

TFT_eSprite Buffer = TFT_eSprite(&lcd);

Face face(Buffer, HEIGHT, WIDTH, EYE);

const eEmotions emotions[eEmotions::EMOTIONS_COUNT] = {
  eEmotions::Normal,
  eEmotions::Angry,
  eEmotions::Glee,
  eEmotions::Happy,
  eEmotions::Sad,
  eEmotions::Worried,
  eEmotions::Focused,
  eEmotions::Annoyed,
  eEmotions::Surprised,
  eEmotions::Skeptic,
  eEmotions::Fustrated,
  eEmotions::Unimpressed,
  eEmotions::Sleepy,
  eEmotions::Suspicious,
  eEmotions::Squint,
  eEmotions::Furious,
  eEmotions::Scared,
  eEmotions::Awe
};

void setup(void) {
// 最初に初期化関数を呼び出します。
  lcd.init();
// 回転方向を 0～3 の4方向から設定します。(4～7を使用すると上下反転になります。)
  lcd.setRotation(0);
// バックライトの輝度を 0～255 の範囲で設定します。
  lcd.setBrightness(128);

	Buffer.setColorDepth(8);
	Buffer.createSprite(WIDTH, HEIGHT);

	face.Expression.GoTo_Normal();
	face.Behavior.Clear();
  face.Behavior.SetEmotion(eEmotions::Normal, 2.0);
  face.Behavior.SetEmotion(eEmotions::Happy, 1.0);

}

void loop() {
	face.Update();
}
