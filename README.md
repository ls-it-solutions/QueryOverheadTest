# Query Overhead Test

This test is for presenting the overhead impact
of queries to a postgresql database.

There are two simple tables related to each other.

The queries are also very simple.

The idea is to retrieve the object structure 
from the database in one query with multiple
result sets and creating and populating the objects
accordingly.

This test showcases only the two queries not 
the generic object relational mapping from the queries.

The choice of approach on how to implement the ORM 
is another task

## Prerequisites

POSTGRESQL database

## setup

```shell
psql -U postgres -f src/sql/TESTSCHEMA.sql
```
This will drop and create the database and populate with the needed test data

