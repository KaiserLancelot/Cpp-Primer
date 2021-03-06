//
// Created by kaiser on 19-3-16.
//

#ifndef CPP_PRIMER_QUERY_BASE_H
#define CPP_PRIMER_QUERY_BASE_H

#include <iostream>
#include <memory>
#include <string>

#include "query.h"

class QueryBase {
  friend class Query;

 protected:
  virtual ~QueryBase() = default;

 private:
  virtual QueryResult Eval(const TextQuery& text) const = 0;
  virtual std::string Rep() const = 0;
};

class WordQuery : public QueryBase {
  friend class Query;

 public:
  explicit WordQuery(const std::string& query_word) : query_word_{query_word} {}
  QueryResult Eval(const TextQuery& text) const override {
    return text.Query(query_word_);
  }
  std::string Rep() const override { return query_word_; }

  std::string query_word_;
};

class NotQuery : public QueryBase {
  friend Query operator~(const Query& operand);

 public:
  explicit NotQuery(const Query& query) : query_{query} {}
  QueryResult Eval(const TextQuery& text) const override;
  std::string Rep() const override { return "~(" + query_.Rep() + ")"; }
  Query query_;
};

class BinaryQuery : public QueryBase {
 public:
  BinaryQuery(const Query& lhs, const Query& rhs, const std::string& op)
      : lhs_(lhs), rhs_(rhs), op_(op) {}
  std::string Rep() const override {
    return "(" + lhs_.Rep() + " " + op_ + " " + rhs_.Rep() + ")";
  }
  Query lhs_, rhs_;
  std::string op_;
};

class AndQuery : public BinaryQuery {
  friend Query operator&(const Query&, const Query&);

 public:
  AndQuery(const Query& lhs, const Query& rhs) : BinaryQuery(lhs, rhs, "&") {}
  QueryResult Eval(const TextQuery& text) const override;
};

class OrQuery : public BinaryQuery {
  friend Query operator|(const Query&, const Query&);

 public:
  OrQuery(const Query& lhs, const Query& rhs) : BinaryQuery(lhs, rhs, "|") {}
  QueryResult Eval(const TextQuery& text) const override;
};

#endif  // CPP_PRIMER_QUERY_BASE_H
