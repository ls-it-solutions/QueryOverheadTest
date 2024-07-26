SELECT 'DROP DATABASE ormtest'
WHERE EXISTS (SELECT FROM pg_database WHERE datname = 'ormtest')\gexec


SELECT 'CREATE DATABASE ormtest'
WHERE NOT EXISTS (SELECT FROM pg_database WHERE datname = 'ormtest')\gexec

\c ormtest

-- DROP TABLE IF EXISTS A CASCADE ;
-- DROP TABLE IF EXISTS B CASCADE ;
-- DROP TABLE IF EXISTS NM_AB CASCADE ;

CREATE TABLE A (ID BIGSERIAL PRIMARY KEY , NAME TEXT);
CREATE TABLE B (ID BIGSERIAL PRIMARY KEY , NAME TEXT);
CREATE TABLE NM_AB (
										 ORDERING BIGSERIAL,
										 SRCID BIGINT NOT NULL REFERENCES A(ID) ON DELETE CASCADE,
										 DSTID BIGINT NOT NULL UNIQUE REFERENCES B(ID) ON DELETE CASCADE
);

INSERT INTO A (NAME) VALUES ('A1');
INSERT INTO B (NAME) VALUES ('B1');

INSERT INTO A (NAME) VALUES ('A2');
INSERT INTO B (NAME) VALUES ('B2');
INSERT INTO B (NAME) VALUES ('B3');
INSERT INTO B (NAME) VALUES ('B4');

INSERT INTO NM_AB (SRCID, DSTID) VALUES (1,1), (2,2), (2,3), (2,4);


SELECT ID, NAME FROM A;
SELECT ID, NAME FROM B;

SELECT NA.SRCID, NA.DSTID, B.NAME FROM B INNER JOIN NM_AB NA on B.ID = NA.DSTID