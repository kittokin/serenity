/*
 * Copyright (c) 2018-2020, Andreas Kling <kling@serenityos.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include <AK/String.h>
#include <AK/Vector.h>

namespace AK {

class LexicalPath {
public:
    LexicalPath() { }
    explicit LexicalPath(const StringView&);

    bool is_valid() const { return m_is_valid; }
    bool is_absolute() const { return m_is_absolute; }
    const String& string() const { return m_string; }

    const String& dirname() const { return m_dirname; }
    const String& basename() const { return m_basename; }
    const String& title() const { return m_title; }
    const String& extension() const { return m_extension; }

    const Vector<String>& parts() const { return m_parts; }

    bool has_extension(const StringView&) const;

    static String canonicalized_path(const StringView&);

private:
    void canonicalize();

    Vector<String> m_parts;
    String m_string;
    String m_dirname;
    String m_basename;
    String m_title;
    String m_extension;
    bool m_is_valid { false };
    bool m_is_absolute { false };
};

template<>
struct Formatter<LexicalPath> : Formatter<StringView> {
    void format(FormatBuilder& builder, const LexicalPath& value)
    {
        Formatter<StringView>::format(builder, value.string());
    }
};

};

using AK::LexicalPath;
