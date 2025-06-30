/*
 * Copyright (C) 2025  Tetex7
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include "clang/AST/ASTContext.h"
#include "clang/AST/DeclGroup.h"
#include "clang/AST/DeclTemplate.h"
#include "clang/AST/PrettyDeclStackTrace.h"
#include "clang/Basic/AddressSpaces.h"
#include "clang/Basic/AttributeCommonInfo.h"
#include "clang/Basic/Attributes.h"
#include "clang/Basic/CharInfo.h"
#include "clang/Basic/DiagnosticParse.h"
#include "clang/Basic/TargetInfo.h"
#include "clang/Basic/TokenKinds.h"
#include "clang/Parse/Parser.h"
#include "clang/Parse/RAIIObjectsForParser.h"
#include "clang/Sema/EnterExpressionEvaluationContext.h"
#include "clang/Sema/Lookup.h"
#include "clang/Sema/ParsedAttr.h"
#include "clang/Sema/ParsedTemplate.h"
#include "clang/Sema/Scope.h"
#include "clang/Sema/SemaCUDA.h"
#include "clang/Sema/SemaCodeCompletion.h"
#include "clang/Sema/SemaObjC.h"
#include "clang/Sema/SemaOpenMP.h"
#include "llvm/ADT/SmallSet.h"
#include "llvm/ADT/StringSwitch.h"
#include <optional>


namespace clang
{

    Parser::DeclGroupPtrTy Parser::TRS_ParseNamespace(DeclaratorContext Context, SourceLocation &DeclEnd, SourceLocation InlineLoc)
    {
        assert(this->getLangOpts().TRS_C99);
        assert(Tok.is(tok::kw_namespace) && "Not a namespace!");
        SourceLocation NamespaceLoc = ConsumeToken(); // eat 'namespace'

        SourceLocation IdentLoc;
        IdentifierInfo* Ident = nullptr;

        ParsedAttributes attrs(AttrFactory);

        if (Tok.isNot(tok::identifier))
        {
            Diag(Tok.getLocation(), diag::err_expected) << tok::identifier;
            SkipUntil(tok::l_brace, StopAtSemi);
            return nullptr;
        }

        Ident = Tok.getIdentifierInfo();
        IdentLoc = ConsumeToken(); // eat the identifier.
        
        return nullptr;
    }
}