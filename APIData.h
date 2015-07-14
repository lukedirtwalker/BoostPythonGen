/***********************************************************************************************************************
**
** Copyright (c) 2011, 2015 ETH Zurich
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
** following conditions are met:
**
**    * Redistributions of source code must retain the above copyright notice, this list of conditions and the following
**      disclaimer.
**    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
**      following disclaimer in the documentation and/or other materials provided with the distribution.
**    * Neither the name of the ETH Zurich nor the names of its contributors may be used to endorse or promote products
**      derived from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
** INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
** DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
** SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
** WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
***********************************************************************************************************************/

#pragma once

#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QList>
#include <QtCore/QDir>

struct EnumData
{
		EnumData(QString name) : enumName_{name} {}
		QString enumName_;
		QString qualifiedName_;
		QList<QPair<QString, QString>> values_;
};

struct ClassAttribute
{
		QString name_;
		QString getterQualified_;
		QString setterQualified_;
};

struct ClassData
{
		ClassData(QString name) : className_{name} {}
		QString className_;
		QString qualifiedName_;
		QStringList baseClasses_;
		QList<ClassAttribute> attributes_;
		QList<EnumData> enums_;
};

struct APIData
{
		QString includePrefix_;
		QStringList includePaths_;
		QList<ClassData> classes_;

		void addIncludeFile(QString filePath)
		{
			if (!includePrefix_.isEmpty()) filePath.prepend(QDir::separator()).prepend(includePrefix_);
			includePaths_ << filePath;
		}
};