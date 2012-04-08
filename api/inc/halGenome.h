/*
 * Copyright (C) 2012 by Glenn Hickey (hickey@soe.ucsc.edu)
 *
 * Released under the MIT license, see LICENSE.txt
 */

#ifndef _HALGENOME_H
#define _HALGENOME_H

#include "halDefs.h"

namespace hal {

/** 
 * Interface for a genome within a hal alignment.  The genome
 * is comprised of a dna sequence, and two segment arrays (top and bottom)
 * which are used to map between ancestral and descendant genomes.  This
 * data is all accessed through iterators. 
 */
class Genome
{
public:
   /** Destructor */
   virtual ~Genome() = 0;
     
   /** Get the name of the genome */
   virtual const std::string& getName() const = 0;

   /** Link back to the containing alignment */
   virtual AlignmentPtr getAlignment() = 0;
   
   /** Link back to the containing read-only alignment */
   virtual AlignmentConstPtr getAlignment() const = 0;

   /** Get the total length of the DNA sequence in the genome*/
   virtual hal_size_t getSequenceLength() const = 0;
   
   /** Get the number of top segements 
    * (which form blocks with ancestor and siblings)
    * in the genome */
   virtual hal_size_t getNumberTopSegments() const = 0;

   /** Get the number of bottom segments
    * (which form blocks with the children)
    * in the genome */
   virtual hal_size_t getNumberBottomSegmentes() const = 0;

   /** Get a segment iterator
    * @param top Specify whether or not returned iterator is a top
    * segment
    * @param position Index in segment array of returned iterator */
   virtual SegmentIteratorPtr getSegmentIterator(hal_bool_t top, 
                                              hal_index_t position) = 0;
   
   /** Get a read-only segment iterator
    * @param top Specify whether or not returned iterator is a top
    * segment
    * @param position Index in segment array of returned iterator */
   virtual SegmentIteratorConstPtr getSegmentIterator(
     hal_bool_t top, hal_index_t position) const = 0;
   
   /** Get genome-specific metadata for this genome */
   virtual MetaDataPtr getMetaData() = 0;

   /** Get read-only instance of genome-specific metadata for this genome */
   virtual MetaDataConstPtr getMetaData() const = 0;
  
};

inline Genome::~Genome() {}

}
#endif