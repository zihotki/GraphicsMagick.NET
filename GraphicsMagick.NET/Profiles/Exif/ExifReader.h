//=================================================================================================
// Copyright 2014-2015 Dirk Lemstra <https://graphicsmagick.codeplex.com/>
//
// Licensed under the ImageMagick License (the "License"); you may not use this file except in 
// compliance with the License. You may obtain a copy of the License at
//
//   http://www.imagemagick.org/script/license.php
//
// Unless required by applicable law or agreed to in writing, software distributed under the
// License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
// express or implied. See the License for the specific language governing permissions and
// limitations under the License.
//=================================================================================================
#pragma once

#include "ExifValue.h"
#include "ExifDataType.h"

using namespace System::Collections::Generic;

namespace GraphicsMagick
{
	//==============================================================================================
	private ref class ExifReader sealed
	{
		//===========================================================================================
	private:
		//===========================================================================================
		generic<typename TDataType>
		where TDataType : value class
			delegate TDataType ConverterMethod(array<Byte>^ data);
		//===========================================================================================
		array<Byte>^ _Data;
		unsigned int _Index;
		bool _IsLittleEndian;
		unsigned int _ExifOffset;
		unsigned int _GPSOffset;
		unsigned int _StartIndex;
		unsigned int _ThumbnailLength;
		unsigned int _ThumbnailOffset;
		//===========================================================================================
		property int RemainingLength
		{
			int get();
		}
		//===========================================================================================
		void AddValues(List<ExifValue^>^ values, unsigned int index);
		//===========================================================================================
		Object^ ConvertValue(ExifDataType dataType, array<Byte>^ data, int numberOfComponents);
		//===========================================================================================
		ExifValue^ CreateValue();
		//===========================================================================================
		array<Byte>^ GetBytes(unsigned int length);
		//===========================================================================================
		unsigned int GetLong();
		//===========================================================================================
		unsigned short GetShort();
		//===========================================================================================
		String^ GetString(unsigned int length);
		//===========================================================================================
		void ExifReader::GetThumbnail(unsigned int offset);
		//===========================================================================================
		generic<typename TDataType>
		where TDataType : value class
			static array<TDataType>^ ToArray(ExifDataType dataType, array<Byte>^ data,
			ConverterMethod<TDataType>^ converter);
		//===========================================================================================
		static Byte ToByte(array<Byte>^ data);
		//===========================================================================================
		double ToDouble(array<Byte>^ data);
		//===========================================================================================
		unsigned int ToLong(array<Byte>^ data);
		//===========================================================================================
		unsigned short ToShort(array<Byte>^ data);
		//===========================================================================================
		float ToSingle(array<Byte>^ data);
		//===========================================================================================
		static String^ ToString(array<Byte>^ data);
		//===========================================================================================
		double ToRational(array<Byte>^ data);
		//===========================================================================================
		SByte ToSignedByte(array<Byte>^ data);
		//===========================================================================================
		int ToSignedLong(array<Byte>^ data);
		//===========================================================================================
		double ToSignedRational(array<Byte>^ data);
		//===========================================================================================
		short ToSignedShort(array<Byte>^ data);
		//===========================================================================================
		bool ValidateArray(array<Byte>^ data, int size);
		//===========================================================================================
		bool ValidateArray(array<Byte>^ data, int size, int stepSize);
		//===========================================================================================
	public:
		//===========================================================================================
		property unsigned int ThumbnailLength
		{
			unsigned int get();
		}
		//===========================================================================================
		property unsigned int ThumbnailOffset
		{
			unsigned int get();
		}
		//===========================================================================================
		List<ExifValue^>^ Read(array<Byte>^ data);
		//===========================================================================================
	};
	//==============================================================================================
}